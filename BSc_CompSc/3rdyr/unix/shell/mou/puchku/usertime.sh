read -p "Enter the username:" m
x=`who|grep $m|cut -b23-`
y=`date -d "$x"`
h=`date -d "$x" +%H`
m=`date -d "$x" +%M`
s=`date -d "$x" +%S`
h1=`date +%H`
m1=`date +%M`
s1=`date +%S`
d=0

s2=`expr $s1 - $s`
if [ $s2 -lt 0 ]
then
	s2=`expr $s2 + 60`
	m=`expr $m + 1`
fi
m2=`expr $m1 - $m`
if [ $m2 -lt 0 ]
then
	m2=`expr $m2 + 60`
	h=`expr $h + 1`
fi
h2=`expr $h1 - $h`
if [ $h2 -lt 0 ]
then
	h2=`expr $h2 + 60`
	d=`expr $d + 1`
fi
echo "duration is:$d day,$h2 hr,$m2 min and $s sec."
