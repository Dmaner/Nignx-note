# 核心代码

## 代码目录

```shell
.
├── modules
├── ngx_http.c
├── ngx_http_cache.h
├── ngx_http_config.h
├── ngx_http_copy_filter_module.c
├── ngx_http_core_module.c
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