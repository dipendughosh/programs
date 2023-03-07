read -p "Give size of the array: " n
t=`expr $n - 1`
for i in `seq 0 $t`
do
	read -p "Give the element at a[$i]: " a[$i]
done
read -p "Give the no to be searched: " s
loc=-1
for i in `seq 0 $t`
do
	if [ ${a[$i]} -eq $s ]
	then
		n=`expr $i + 1`
		loc=$n
	fi
done
if [ $loc -eq -1 ]
then 
	echo "not found"
else
	echo "found"
fi
