read -p "Give the size of array: " n
t=`expr $n - 1`
for i in `seq 0 $t`
do
	read -p "Give elements a[$i]: " a[$i]
done
read -p "give the no to be searched: " s
loc=-1
l=0
while [ $l -le $t ]
do
	m=`echo "($l+$t)/2"|bc`
	echo $m
	if [ ${a[$m]} -eq $s ]
	then
		n=`expr $m + 1`
		loc=$n
		break
	elif [ ${a[$m]} -ge $s ]
	then
		t=`expr $m - 1`
	else
		l=`expr $m + 1`
	fi
done
if [ $loc -eq -1 ]
then 
	echo "not found"
else
	echo "found at " $loc
fi



