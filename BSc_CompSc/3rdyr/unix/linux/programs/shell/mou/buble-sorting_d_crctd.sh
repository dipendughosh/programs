read -p "Give no of elements to b sorted: " n
t=`expr $n - 1`
for i in `seq 0 $t`
do
	read -p "Give elements to be sorted at a[$i]:= " a[$i]
done
for i in `seq 0 $t`
do
	for j in `seq 0 $i`
	do
		x=`expr $j + 1`
		if [ ${a[$j]} -gt ${a[$x]} ]
		then
			s=${a[$j]}
			a[$j]=${a[$x]}
			a[$x]=$s
		fi
	done
done
for i in `seq 0 $t`
do
	echo "sorted elements are a[$i]:= " ${a[$i]}
done



