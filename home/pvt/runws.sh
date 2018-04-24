#!/bin/sh
# Copyright PVT Solar Inc. 2009
#
SCRIPT_REVISION="Web Services Startup Script Revision Revision 2.0.21"

echo $SCRIPT_REVISION > /tmp/logs/runpvtwsversion.log

chmod 770 /home/pvt/pvtcertificatemanager
chmod 660 /home/pvt/pvtwsclientconfig.443
sync
sleep 5

AXIS2C_HOME='/usr/local/axis2c'
export AXIS2C_HOME
LD_LIBRARY_PATH=:.:/usr/local/axis2c/lib
export LD_LIBRARY_PATH
for ((;;))
do
   ./pvtcertificatemanager
   ./pvtwsclient
   sleep 30
   date                     >> /home/pvt/pvtrestart.log
   echo "   ws restarted" >> /home/pvt/pvtrestart.log
   echo ""                >> /home/pvt/pvtrestart.log
done
