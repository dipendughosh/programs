read -p "Give no of elements to b sorted: " n
t=`expr $n - 1`
for i in `seq 0 $t`
do
	read -p "Give elements to be sorted at a[$i]=: " a[$i]
done
for i in `seq 0 $t`
do
	for j in `seq 0 $i`
	do
		m=`expr $j + 1`
		if [ ${a[$j]} -gt ${a[$m]} ]
		then
			s=${a[$j]}
			a[$j]=${a[$m]}
			a[$m]=$s
		fi
	done
done
for i in `seq 0 $t`
do
	echo "sorted elements are a[$i]:= " ${a[$i]}
done



