#!/bin/sh
# Copyright PVT Solar Inc. 2009
#
# Web Services Updater Script

AXIS2C_HOME='/usr/local/axis2c'
export AXIS2C_HOME
LD_LIBRARY_PATH=:.:/usr/local/axis2c/lib
export LD_LIBRARY_PATH

if [ -f pvtupdaterled ] && [ -f staging/updatelevel.dat ]
then
   ./pvtupdaterled
else
   ./pvtupdater
fi
