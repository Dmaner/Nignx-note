
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_SHMEM_H_INCLUDED_
#define _NGX_SHMEM_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>

/*  */
typedef struct {
    u_char      *addr;      /* 共享内存的起始地址 */
    size_t       size;      
    ngx_str_t    name;      
    ngx_log_t   *log;       /* 记录日志对象 */
    ngx_uint_t   exists;    /* 是否已经分配  */
} ngx_shm_t;


ngx_int_t ngx_shm_alloc(ngx_shm_t *shm);
void ngx_shm_free(ngx_shm_t *shm);


#endif /* _NGX_SHMEM_H_INCLUDED_ */
