# Nginx 源码阅读 & 实战

该项目主要对`Nginx`进行源码分析，并添加中文注释，以及使用`Nginx`进行实战

## 环境

- Ubuntu 18.04
- Nignx 1.96.6

## 简易编译过程

```shell
cd nginx-1.19.6/
# --add-module=/home/usrname/nginx-note/mytest 添加自定义HTTP模块
./configure --add-module=/home/usrname/nginx-note/mytest --prefix=/usr/local/nginx
make
sudo make install
# 测试安装是否成功
/usr/local/nginx/sbin/nginx -t
# 用alias起个别名
alias nginx='/usr/local/nginx/sbin/nginx'
```

## nginx简易命令

```shell
nginx -t           /* 测试nginx是否能正常运行 */
nginx -s stop      /* 快速停止 */
nginx -s quit      /* 处理完请求再停止 */
nginx -c my.conf   /* 采用自己的配置文件 */
```

## 代码结构

- [核心模块](src/core/Readme.md)
- [事件模块](src/event/Readme.md)
- [HTTP模块](src/http/Readme.md)
- [邮件模块](src/mail/Readme.md)
- [进程通信&同步](src/os/Readme.md)

## 实战

- Nginx 开发HTTP模块

## 疑问

- Nginx 异步I/O
- [Nginx 基础架构](ngx-architecture.md)


## 参考

- 深入理解Nignx (第二版)