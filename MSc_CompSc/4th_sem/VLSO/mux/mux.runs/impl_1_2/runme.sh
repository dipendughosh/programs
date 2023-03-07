#!/bin/sh

# 
# PlanAhead(TM)
# runme.sh: a PlanAhead-generated ExploreAhead Script for UNIX
# Copyright 1986-1999, 2001-2010 Xilinx, Inc. All Rights Reserved.
# 

echo "This script was generated under a different operating system."
echo "Please update the PATH and LD_LIBRARY_PATH variables below, before executing this script"
exit

if [ -z "$PATH" ]; then
  PATH=C:\\Xilinx\\12.3\\ISE_DS\\ISE\\bin\\nt;C:\\Xilinx\\12.3\\ISE_DS\\ISE\\lib\\nt;C:\\Xilinx\\12.3\\ISE_DS\\common\\bin\\nt;C:\\Xilinx\\12.3\\ISE_DS\\common\\lib\\nt
else
  PATH=C:\\Xilinx\\12.3\\ISE_DS\\ISE\\bin\\nt;C:\\Xilinx\\12.3\\ISE_DS\\ISE\\lib\\nt;C:\\Xilinx\\12.3\\ISE_DS\\common\\bin\\nt;C:\\Xilinx\\12.3\\ISE_DS\\common\\lib\\nt:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=
else
  LD_LIBRARY_PATH=:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD=`dirname "$0"`
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG $* >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

EAStep ngdbuild -intstyle ise -p xc6vlx75tff484-1 -uc "mux.ucf" "mux.edf"
EAStep map -intstyle ise -w "mux.ngd"
EAStep par -intstyle ise "mux.ncd" -w "mux_routed.ncd"
EAStep trce -intstyle ise -o "mux.twr" -v 30 -l 30 "mux_routed.ncd" "mux.pcf"
EAStep xdl -secure -ncd2xdl -nopips "mux_routed.ncd" "mux_routed.xdl"
