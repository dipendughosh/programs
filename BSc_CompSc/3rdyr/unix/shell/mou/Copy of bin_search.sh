read -p "Give the size of array: " n
t=`expr $n - 1`
for i in `seq 0 $t`
do
	read -p "Give elements a[$i]: " a[$i]

done
read -p "give the no to be searched: " s
loc=-1
l=0
while [ l != $t ]
do
	m=`echo "($l + $t)/2"| bc`

	if [ ${a[$m]} -eq $t ]
	then
		n=`expr $m + 1`
		loc=$n
		
	elif [ ${a[$m]} -gt $t ]
	then
		t=$m
	elif [ ${a[$m]} -lt $t ]
	then
		l=$m
	fi
done
if [ $loc -eq -1 ]
then 
	echo "not found"
else
	echo "found"
fi



