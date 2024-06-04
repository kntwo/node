#### day1
1. fedora
2. dnf install gcc-c++
3. ssh enable
    1. systemctl  is-enabled  sshd   //查询SSH服务是否开启
    2. systemctl restart sshd.service   // 重启 ssh 服务
    3. systemctl enable sshd  // 自动启动
4. 终端采用MobaXterm软件，用ssh协议创建面向Linux系统连接
5. man ls, ls --help, info ls, reboot, shutdown,ls -al
6. '*'任意字符串, '?'单个字符    //通配符
7. ln  //符号链接link
8. nl  //显示行号number lines
9. tar -cvf 
    1. tar -xvf
10. mount //挂载磁盘 umount //磁盘卸载
11. ps,kill 
#### day 2
1. vim 
   1. :set nu,set nonu
   2. :/a 搜索a
   3. yy,dd,p
   4. yG,ygg,dG,dgg
   5. u,ctrl+r
   6. 按0       移动到光标所在行的"行首"  (^)
   7. 按$       移动到光标所在行的"行尾"
   8. 按G       移动到文章的最后    
   9. 按gg      移动到文章的开头
2. c++
   1. inline
   2. 函数重载 参数不同可共存
   3. 函数参数可带默认值
#### day 4
1. 友元函数和友元类
2. 构造函数
   1. func(int a):b(a){}
3. dynastmy ram 
   1. malloc realloc calloc free
   2. new delete
4. virtual base class
5. constructor and destructor can't inherit

