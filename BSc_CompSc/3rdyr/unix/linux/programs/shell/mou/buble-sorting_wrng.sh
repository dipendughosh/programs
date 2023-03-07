read -p "Give no of elements to b sorted: " n
t=`expr $n - 1`
for i in `seq 0 $t`
do
	read -p "Give elements to be sorted at a[$i]=: " a[$i]
done
for i in `seq $t 0`
do
	for j in `seq 0 $i`
	do
		if [ a[$j] -gt a[$j + 1] ]
		then
			s=a[$j]
			a[$j]=a[$j + 1]
			a[$j + 1]=s
		fi
	done
done
for i in `seq 0 $t`
do
	echo "sorted elements are a[$i]:= " a[$i]
done



