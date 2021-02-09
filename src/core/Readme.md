# 核心代码

## 代码目录

```shell
.
├── nginx.c
├── nginx.h
├── ngx_array.c
├── ngx_array.h
├── ngx_buf.{c, h} // 缓冲区结构
├── ngx_conf_file.{c, h} // 配置文件解析
├── ngx_config.h
├── ngx_connection.c
├── ngx_connection.h
├── ngx_core.h    // 声明各种模块
├── ngx_cpuinfo.c
├── ngx_crc32.c
├── ngx_crc32.h
├── ngx_crc.h
├── ngx_crypt.c
├── ngx_crypt.h
├── ngx_cycle.{c, h} // Nginx各进程的主要工作流程都是以ngx_cycle_t结构体作为基础的
├── ngx_file.c
├── ngx_file.h
├── ngx_hash.{c, h} // nginx键值对类型
├── ngx_inet.c
├── ngx_inet.h
├── ngx_list.{c, h} // nginx链表
├── ngx_log.c
├── ngx_log.h
├── ngx_md5.c
├── ngx_md5.h
├── ngx_module.{c, h} // nginx模块文件
├── ngx_murmurhash.c
├── ngx_murmurhash.h
├── ngx_open_file_cache.c
├── ngx_open_file_cache.h
├── ngx_output_chain.c
├── ngx_palloc.c
├── ngx_palloc.h
├── ngx_parse.c
├── ngx_parse.h
├── ngx_parse_time.c
├── ngx_parse_time.h
├── ngx_proxy_protocol.c
├── ngx_proxy_protocol.h
├── ngx_queue.c
├── ngx_queue.h
├── ngx_radix_tree.c
├── ngx_radix_tree.h
├── ngx_rbtree.c
├── ngx_rbtree.h
├── ngx_regex.c
├── ngx_regex.h
├── ngx_resolver.c
├── ngx_resolver.h
├── ngx_rwlock.c
├── ngx_rwlock.h
├── ngx_sha1.c
├── ngx_sha1.h
├── ngx_shmtx.c
├── ngx_shmtx.h
├── ngx_slab.c
├── ngx_slab.h
├── ngx_spinlock.c
├── ngx_string.{c, h} // 字符串结构
├── ngx_syslog.c
├── ngx_syslog.h
├── ngx_thread_pool.c
├── ngx_thread_pool.h
├── ngx_times.c
├── ngx_times.h
```