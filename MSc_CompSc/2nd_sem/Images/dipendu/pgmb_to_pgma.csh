#!/bin/csh
#
g++ -c -I$HOME/include pgmb_to_pgma.C >& compiler.txt
if ( $status != 0 ) then
  echo "Errors compiling pgmb_to_pgma.C"
  exit
endif
rm compiler.txt
#
g++ pgmb_to_pgma.o ~/libcpp/$ARCH/pgma_io.o ~/libcpp/$ARCH/pgmb_io.o -lm
if ( $status != 0 ) then
  echo "Errors linking and loading pgmb_to_pgma.o"
  exit
endif
#
rm pgmb_to_pgma.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/$ARCH/pgmb_to_pgma
#
echo "Executable installed as ~/bincpp/$ARCH/pgmb_to_pgma"
