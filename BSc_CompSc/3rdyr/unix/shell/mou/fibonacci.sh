read -p "give the limit  of the series: " n
f1=0
f2=1
echo $f1 $f2
for i in `seq 3 $n`
do
	f3=`echo "($f1 + $f2)" | bc`
	echo $f3
	f1=$f2
	f2=$f3
done




series ta 0 1 1 2 3 tai f1 ta 1 na 0 hbe
r f3 ta dclr korar dekr nai