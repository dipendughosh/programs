if [ $# -eq 0 ]
then
	echo "ERROR:- No User name entered :-"
	read -p "Enter User name:- " nm
else
	nm=$1
fi
x=(`who`)
#echo ${x[3]}
#date -d "${x[3]}"
d=0
s1=`date -d "${x[3]}" +%S`
m1=`date -d "${x[3]}" +%M`
h1=`date -d "${x[3]}" +%H`
s2=`date +%S`
m2=`date +%M`
h2=`date +%H`
s1=`expr $s2 - $s1`
m1=`expr $m2 - $m1`
h1=`expr $h2 - $h1`
if [ $s1 -lt 0 ]
then
	s1=`expr $s1 + 60`
	m1=`expr $m1 - 1`
fi
if [ $m1 -lt 0 ]
then
	m1=`expr $m1 + 60`
	h1=`expr $h1 - 1`
fi
if [ $h1 -lt 0 ]
then
	h1=`expr $h1 + 24`
	d=1
fi
echo "dd : hh : mm : ss"
echo "$d : $h1 : $m1 : $s1"
