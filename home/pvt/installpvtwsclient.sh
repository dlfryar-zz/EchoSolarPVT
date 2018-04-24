#!/bin/sh
# Copyright PVT Solar Inc. 2008
#
# This script installs the PVT web service agent. Do manual steps before running script.

#
####  Log in as pvt
#    pvt
#    pvt
#
####  Change to super user
#    su
#    [enter password]
#find and kill the runpvtws.sh and pvtwsclient processes, in that order
# ps -A
# kill xxx where xxx is the process id found in the ps command output
#
# 3. ssh-file transfer  pvtwsinstall.tar.gz to /home/pvt 
#
# 4.   cd /home/pvt
# rm -r -f /usr/local/axis2c
# gunzip pvtwsinstall.tar.gz 
# tar xvf pvtwsinstall.tar
####  make script executable by root
# chmod 700 installpvtwsclient.sh
#  run . ./installpvtwsclient.sh

cd /home/pvt

rm pvtws*install.tar
rm -r -f /usr/local/axis2c

echo " setting permissions"
chmod 666 axis2c_bin-1.6.0-arm-ssl-patched-7500.tar
chmod 744 installpvtwsclient.sh
chmod 644 pvtsolar_axis2c.xml
chmod 770 pvtwsclient
chmod 770 pvtupdater
chmod 770 otsmanager
chmod 660 pvtwsclientconfig.dat
chmod 770 runws.sh
chmod 770 runupdater.sh
chmod 770 runotsmanager.sh
chmod 644 tomcat.pem
chmod 644 sshd_config


 
cd /home/pvt


echo "installing axis2c arm binary distribution to /usr/local"
mv  /home/pvt/axis2c_bin-1.6.0-arm-ssl-patched-7500.tar  /usr/local
cd /usr/local 
pwd
rm -r -f /usr/local/axis2c
tar xvf axis2c_bin-1.6.0-arm-ssl-patched-7500.tar
rm axis2c_bin-1.6.0-arm-ssl-patched-7500.tar

cd /usr/local/axis2c
pwd
cp  /usr/local/axis2c/axis2.xml /usr/local/axis2c/axis2.xml.bak
cp  /home/pvt/pvtsolar_axis2c.xml  /usr/local/axis2c/axis2.xml


echo "removing unknown-ordered pvt and web service components from startup"
sed -i -e  '/runws.sh/d' /etc/init.d/applicationstartup
sed -i -e  '/runpvt.sh/d' /etc/init.d/applicationstartup
sed -i -e  '/otsmanager/d' /etc/init.d/applicationstartup
sed -i -e  '/runotsmanager.sh/d' /etc/init.d/applicationstartup
sed -i -e  '/runupdater.sh/d' /etc/init.d/applicationstartup


echo "adding ordered pvt and web service components from startup"
echo "adding one-time script manager to startup"
echo "/home/pvt/runotsmanager.sh"  >> /etc/init.d/applicationstartup
echo "adding updater to startup"
echo "/home/pvt/runupdater.sh"  >> /etc/init.d/applicationstartup
echo "adding pvt to startup"
echo "/home/pvt/runpvt.sh &"  >> /etc/init.d/applicationstartup
echo "adding web service to startup"
echo "/home/pvt/runws.sh &"  >> /etc/init.d/applicationstartup


echo "ensuring minimum security precautions"
echo "disable telnet and ftp"
cp /etc/inetd.conf  /etc/inetd.conf.bak
/usr/sbin/update-inetd --disable telnet
/usr/sbin/update-inetd --disable ftp

echo "edit /etc/inetd.conf to re-enable"


echo "disable packet forwarding"
echo "0" > /proc/sys/net/ipv4/ip_forward


echo "remove apache from startup"
update-rc.d -f apache2 remove

echo "remove avahi from startup"
update-rc.d -f avahi-daemon remove

cp  /etc/network/interfaces /etc/network/interfaces.bak
mv  /home/pvt/interfaces /etc/network/interfaces

echo  "disabling root login on ssh"
echo "changing PermitRootLogin from yes to no in sshd_config"
cp /etc/ssh/sshd_config /etc/ssh/sshd_config.bak
cp /home/pvt/sshd_config  /etc/ssh

sync
echo 3 > /proc/sys/vm/drop_caches
sync

cd /home/pvt

echo "reboot now if no errors indicated"
