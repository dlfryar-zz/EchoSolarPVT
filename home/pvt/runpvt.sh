#!/bin/sh
# Copyright PVT Solar Inc. 2009
#
# PVT Controller Startup Script

export LD_LIBRARY_PATH=:.:/.

#Factory reset support

if ! [ -d factoryreset ]
then
   mkdir factoryreset
fi

if [ -f pvt_factoryreset.tar.gz ]
then
   tar zxvf pvt_factoryreset.tar.gz -C factoryreset
   rm -f pvt_factoryreset.tar.gz
fi

# PVT-1000
if uname -r | grep 2.6.21-ts > /dev/null
then
   if [ -f cp2101_PVT-CPU.ko ]
   then
      if ! cmp -s cp2101_PVT-CPU.ko /lib/modules/2.6.21-ts/kernel/drivers/usb/serial/cp2101.ko
      then
         cp cp2101_PVT-CPU.ko /lib/modules/2.6.21-ts/kernel/drivers/usb/serial/cp2101.ko
      fi
   fi

   modprobe cp2101

   if [ -f pvt_PVT-CPU ]
   then
      cp pvt backup
      mv pvt_PVT-CPU pvt
      chmod 770 pvt
      rm pvtrestart.log
   fi

   if [ -f libjansson_PVT-CPU.so.4 ]
   then
      cp libjansson.so.4 backup
      mv libjansson_PVT-CPU.so.4 libjansson.so.4
   fi

   if [ -f ws_factoryreset_PVT-CPU.tar.gz ]
   then
      tar zxvf ws_factoryreset_PVT-CPU.tar.gz -C factoryreset
      rm -f ws_factoryreset_PVT-CPU.tar.gz
   fi

#  if [ -f pvtupdaterled_PVT-CPU ]
#  then
#     cp pvtupdaterled backup
#     mv pvtupdaterled_PVT-CPU pvtupdaterled
#     chmod 770 pvtupdaterled
#  fi
fi

#CTR-2
if uname -r | grep 2.6.24.4 > /dev/null
then
   echo Loading USB serial support
   modprobe usbserial
   insmod cp2101.ko
   insmod pl2303.ko

   if [ -f pvt_TS-7500 ]
   then
      cp pvt backup
      mv pvt_TS-7500 pvt
      chmod 770 pvt
      rm pvtrestart.log
   fi

   if [ -f yasdi_TS-7500.ini ]
   then
      mv yasdi_TS-7500.ini yasdi.ini
   fi

   if [ -f libjansson_TS-7500.so.4 ]
   then
      cp libjansson.so.4 backup
      mv libjansson_TS-7500.so.4 libjansson.so.4
   fi

   if [ -f ws_factoryreset_TS-7500.tar.gz ]
   then
      tar zxvf ws_factoryreset_TS-7500.tar.gz -C factoryreset
      rm -f ws_factoryreset_TS-7500.tar.gz
   fi

#  if [ -f pvtupdaterled_TS-7500 ]
#  then
#     cp pvtupdaterled backup
#     mv pvtupdaterled_TS-7500 pvtupdaterled
#     chmod 770 pvtupdaterled
#  fi
fi

if [ -f revision.h ]
then
   rm revision.h
fi

if [ -f applicationstartup ]
then
   echo "Updating applicationstartup"
   sleep 5   #allow time for applicationstartup to terminate
   mv applicationstartup /etc/init.d
   chmod 755 /etc/init.d/applicationstartup
   sync
fi

date                       >> /home/pvt/pvtrestart.log
echo "   system restarted" >> /home/pvt/pvtrestart.log
echo ""                    >> /home/pvt/pvtrestart.log

./runts.sh &

for ((;;))
do
   ./pvt -q
   sleep 30

   date                    >> /home/pvt/pvtrestart.log
   echo "   pvt restarted" >> /home/pvt/pvtrestart.log
   echo ""                 >> /home/pvt/pvtrestart.log
done
