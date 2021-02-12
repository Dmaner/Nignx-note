# Nginx 源码阅读

## 学习环境

- Ubuntu 18.04
- Nignx 1.96.1

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

- [核心模块](src/core)
- [事件模块](src/event)
- [HTTP模块相关代码](./src/http)

## 学习笔记

- Nginx 开发HTTP模块
- Nginx 基础架构


## 参考

- 深入理解Nignx (第二版)