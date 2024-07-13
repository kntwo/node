1. 操作系统是硬件和软件之间的桥梁
由操作系统调用硬件.
![](2022-11-14-17-06-27.png)
2. centos7 root/305750
3. restart network
sudo nmcli network off
sudo nmcli network on
1. ps -ef | grep dm
2. tree
3. 查看所有已安装的服务
systemctl list-unit-files --type=service
4. centos 关闭防火墙
sudo systemctl stop firewalld
sudo systemctl disable firewalld
5. rpm
rpm -qa | grep mariadb
rpm -e --nodeps 包
