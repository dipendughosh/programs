read -p "Enter number of elements of the array:- " n
n=`expr $n - 1`
echo "Enter elements : - "
for i in `seq 0 $n`
do
	read -p "a[$i] = " a[$i]
done
echo "Before sorting:-"
for i in `seq 0 $n`
do
	echo "a[$i] = " ${a[$i]}
done
for i in `seq 0 $n`
do
	x=`expr $i + 1`
	for j in `seq $x $n`
	do
		if [ ${a[$i]} -ge ${a[$j]} ]
		then
			t=${a[$i]}
			a[$i]=${a[$j]}
			a[$j]=$t
		fi
	done
done
echo "After sorting:-"
for i in `seq 0 $n`
do
	echo "a[$i] = " ${a[$i]}
done
