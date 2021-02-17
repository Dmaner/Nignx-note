# HTTP模块

## `ngx_http_module_t`模块

HTTP核心模块，负责配置文件解析

- 源码

```c++
/* src/http/ngx_http_config.h */
typedef struct {
    /* 解析http{...}前回调 */
    ngx_int_t   (*preconfiguration)(ngx_conf_t *cf);
    /* 解析http{...}后回调 */
    ngx_int_t   (*postconfiguration)(ngx_conf_t *cf);

    /* 创建用于存储HTTP全局配置项的结构体 */
    void       *(*create_main_conf)(ngx_conf_t *cf);
    /* 解析完http{...}配置项后回调 */
    char       *(*init_main_conf)(ngx_conf_t *cf, void *conf);

    /* 创建用于存储可同时出现在http{...}、server{...}级别配置项的结构体 */
    void       *(*create_srv_conf)(ngx_conf_t *cf);
    /* 出现在http{...}级别中的配置项值合并到server{...}级别配置项中 */
    char       *(*merge_srv_conf)(ngx_conf_t *cf, void *prev, void *conf);

    /*创建用于存储可同时出现在http{...}、server{...}、location{...}级别配置项的结构体  */
    void       *(*create_loc_conf)(ngx_conf_t *cf);
    /* 出现在http{...}、server{...}级别中的配置项值合并到location{...}级别配置项中 */
    char       *(*merge_loc_conf)(ngx_conf_t *cf, void *prev, void *conf);
} ngx_http_module_t;
```

## HTTP请求处理11个阶段

- 状态定义

```c
/* /src/http/ngx_http_core_module.h */
/* HTTP请求处理的十一个阶段 */
typedef enum {
    NGX_HTTP_POST_READ_PHASE = 0,   /* 在接收到完整的HTTP头部后处理的HTTP阶段 */
    NGX_HTTP_SERVER_REWRITE_PHASE,  /* 在将请求的URI与location表达式匹配前，修改请求的URI */
    NGX_HTTP_FIND_CONFIG_PHASE,     /* 根据URI寻找匹配的表达式 */
    NGX_HTTP_REWRITE_PHASE,         /* 在NGX_HTTP_FIND_CONFIG_PHASE阶段寻找到匹配的location之后再修改请求的URI */
    NGX_HTTP_POST_REWRITE_PHASE,    /* 这一阶段是用于在rewrite重写URL后，防止错误的nginx.conf配置导致死循环 */
    NGX_HTTP_PREACCESS_PHASE,       /* 表示在处理NGX_HTTP_ACCESS_PHASE阶段决定请求的访问权限前，HTTP模块可以介入的处理阶段 */
    NGX_HTTP_ACCESS_PHASE,          /* 这个阶段用于让HTTP模块判断是否允许这个请求访问Nginx服务器 */
    NGX_HTTP_POST_ACCESS_PHASE,     /* 在NGX_HTTP_ACCESS_PHASE阶段中，当HTTP模块的handler处理函数返回不允许访问的错误码时，
                                     * 这里将负责向用户发送拒绝服务的错误响应 
                                     */
    NGX_HTTP_PRECONTENT_PHASE,      /* 当HTTP请求访问静态文件资源时，try_files配置项可以使这个请求顺序地访问多个静态文件资源，
                                     * 如果某一次访问失败，则继续访问try_files中指定的下一个静态资源 
                                     */
    NGX_HTTP_CONTENT_PHASE,         /* 用于处理HTTP请求内容的阶段，这是大部分HTTP模块最愿意介入的阶段 */
    NGX_HTTP_LOG_PHASE              /* 处理完请求后记录日志的阶段 */
} ngx_http_phases;
```

## HTTP框架初始化阶段

![image](../../images/ngx_http_framwork_init.png)

## 代码目录

```shell
.
├── modules
├── ngx_http.c
├── ngx_http_cache.h
├── ngx_http_config.h   // http核心模块
├── ngx_http_copy_filter_module.c
├── ngx_http_core_module.c  // 存储http{...}, server{...}, location{...} 配置项
├── ngx_http_core_module.h
├── ngx_http_file_cache.c
├── ngx_http.h
├── ngx_http_header_filter_module.c
├── ngx_http_parse.c
├── ngx_http_postpone_filter_module.c
├── ngx_http_request_body.c
├── ngx_http_request.{c, h} // 处理http请求报文
├── ngx_http_script.c
├── ngx_http_script.h
├── ngx_http_special_response.c
├── ngx_http_upstream.c
├── ngx_http_upstream.h
├── ngx_http_upstream_round_robin.c
├── ngx_http_upstream_round_robin.h
├── ngx_http_variables.c
├── ngx_http_variables.h
├── ngx_http_write_filter_module.c
└── v2
    ├── ngx_http_v2.c
    ├── ngx_http_v2_encode.c
    ├── ngx_http_v2_filter_module.c
    ├── ngx_http_v2.h
    ├── ngx_http_v2_huff_decode.c
    ├── ngx_http_v2_huff_encode.c
    ├── ngx_http_v2_module.c
    ├── ngx_http_v2_module.h
    └── ngx_http_v2_table.c
```