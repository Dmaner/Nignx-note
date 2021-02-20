# Nginx进程通信&同步方式

# unix

## 代码目录

```shell
.
├── ngx_alloc.c
├── ngx_alloc.h
├── ngx_atomic.h
├── ngx_channel.{c, h}  // Nginx频道
├── ngx_daemon.c        
├── ngx_darwin.h
├── ngx_darwin_config.h
├── ngx_darwin_init.c
├── ngx_darwin_sendfile_chain.c
├── ngx_dlopen.c
├── ngx_dlopen.h
├── ngx_errno.c
├── ngx_errno.h
├── ngx_file_aio_read.c
├── ngx_files.c
├── ngx_files.h
├── ngx_freebsd.h
├── ngx_freebsd_config.h
├── ngx_freebsd_init.c
├── ngx_freebsd_sendfile_chain.c
├── ngx_gcc_atomic_amd64.h
├── ngx_gcc_atomic_ppc.h
├── ngx_gcc_atomic_sparc64.h
├── ngx_gcc_atomic_x86.h
├── ngx_linux.h
├── ngx_linux_aio_read.c
├── ngx_linux_config.h
├── ngx_linux_init.c
├── ngx_linux_sendfile_chain.c
├── ngx_os.h
├── ngx_posix_config.h
├── ngx_posix_init.c
├── ngx_process.{c, h}      // nginx进程，信号
├── ngx_process_cycle.c
├── ngx_process_cycle.h
├── ngx_readv_chain.c
├── ngx_recv.c
├── ngx_send.c
├── ngx_setaffinity.c
├── ngx_setaffinity.h
├── ngx_setproctitle.c
├── ngx_setproctitle.h
├── ngx_shmem.{c, h}        // 共享内存
├── ngx_socket.c
├── ngx_socket.h
├── ngx_solaris.h
├── ngx_solaris_config.h
├── ngx_solaris_init.c
├── ngx_solaris_sendfilev_chain.c
├── ngx_sunpro_amd64.il
├── ngx_sunpro_atomic_sparc64.h
├── ngx_sunpro_sparc64.il
├── ngx_sunpro_x86.il
├── ngx_thread.h
├── ngx_thread_cond.c
├── ngx_thread_id.c
├── ngx_thread_mutex.c
├── ngx_time.c
├── ngx_time.h
├── ngx_udp_recv.c
├── ngx_udp_send.c
├── ngx_udp_sendmsg_chain.c
├── ngx_user.c
├── ngx_user.h
└── ngx_writev_chain.c
```

# windows

- 待写