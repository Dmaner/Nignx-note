# 事件模块

## 简述

事件模块主要处理事件的收集，处理和分发，同时不同系统处理事件的方式不同，故Nginx为不同操作系统定义了不同的事件驱动模块
- `ngx_epoll_module`
- `ngx_kqueue_module`
- `ngx_poll_module`
- `ngx_select_module`
- `ngx_devpoll_module`
- `ngx_eventport_module`
- `ngx_aio_module`
- `ngx_rtsig_module`
- 基于Windows的`ngx_select_module`模块
初始化时采用`ngx_event_core_module`选择其一

## 事件模块初始化

![images](../../images/ngx_event_module_init.png)

## 事件处理核心模块`ngx_event_module_t`

- 源码

```c
/* src/event/ngx_event.h */
typedef struct {
    ngx_str_t              *name;   

    // 解析，初始化配置项
    void                 *(*create_conf)(ngx_cycle_t *cycle);
    char                 *(*init_conf)(ngx_cycle_t *cycle, void *conf);

    // 实现事件驱动机制所需的10个抽象方法
    // e.g.: 在事件框架添加/删除事件
    ngx_event_actions_t     actions;
} ngx_event_module_t;
```

## `Nginx`事件结构体 - `ngx_event_t`

`Nginx`事件都由`ngx_event_t`表示，其中较为重要的部分是其`hander`属性

- 源码

[src/event/ngx_event.h](ngx_event.h#L30)

## 被动连接`ngx_connection_t`

被动连接在`nginx`中指得是客户端向服务器发起的连接，服务器被动接受

- 源码

[src/core/ngx_connection.h](../core/ngx_connection.h)

## 主动连接`ngx_peer_connection_t`

主动连接指`Nginx`主动向其他服务器发起连接

- 源码

[src/event/ngx_event_connection.h](ngx_event_connect.h)

## 代码结构

```shell
event
│  ngx_event.{c, h}             // 事件模块核心结构体实现
│  ngx_event_accept.c
│  ngx_event_acceptex.c
│  ngx_event_connect.{c, h}     // nginx主动连接结构体实现
│  ngx_event_connectex.c
│  ngx_event_openssl.c
│  ngx_event_openssl.h
│  ngx_event_openssl_stapling.c
│  ngx_event_pipe.c
│  ngx_event_pipe.h
│  ngx_event_posted.c
│  ngx_event_posted.h
│  ngx_event_timer.c
│  ngx_event_timer.h
│  ngx_event_udp.c
│  Readme.md
│
└─modules   // 不同系统对应的事件处理模块
        ngx_devpoll_module.c
        ngx_epoll_module.c
        ngx_eventport_module.c
        ngx_iocp_module.c
        ngx_iocp_module.h
        ngx_kqueue_module.c
        ngx_poll_module.c
        ngx_select_module.c
        ngx_win32_poll_module.c
        ngx_win32_select_module.c
```