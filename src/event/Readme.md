# 事件模块

## 简介

Nginx为不同操作系统定义了不同的事件驱动模块
- ngx_epoll_module
- ngx_kqueue_module
- ngx_poll_module
- ngx_select_module
- ngx_devpoll_module
- ngx_eventport_module
- ngx_aio_module
- ngx_rtsig_module
- 基于Windows的ngx_select_module模块
初始化时采用ngx_event_core_module选择其一

## 事件模块初始化

![images](../../images/ngx_event_module_init.png)

## 代码结构

```shell
event
│  ngx_event.c
│  ngx_event.h
│  ngx_event_accept.c
│  ngx_event_acceptex.c
│  ngx_event_connect.c
│  ngx_event_connect.h
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