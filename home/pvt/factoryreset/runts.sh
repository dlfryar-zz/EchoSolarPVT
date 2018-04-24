#!/bin/sh
# Copyright PVT Solar Inc. 2009
#
# PVT Time Synchronization Script

# Synchronize system clock to battery backed clock every 24 hours

for ((;;))
do
   if uname -r | grep 2.6.21-ts > /dev/null #PVT-CPU
   then
      hwclock --hctosys
   fi

   if uname -r | grep 2.6.24.4 > /dev/null #TS-7500
   then
      /initrd/sbin/ts7500ctl --getrtc &> /dev/null
   fi

   sleep 86400
done
