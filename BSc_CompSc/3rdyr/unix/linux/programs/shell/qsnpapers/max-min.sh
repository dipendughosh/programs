read -p "Enter number of elements:- " n
echo "Enter the values------"
n=`expr $n - 1`
for i in `seq 0 $n`
do
	read -p "a[$i] = " a[$i]
done
max=${a[0]}
min=${a[0]}
for i in `seq $n`
do
	if [ ${a[$i]} -lt $min ]
	then
		min=${a[$i]}
	fi
	if [ ${a[$i]} -gt $max ]
	then
		max=${a[$i]}
	fi
done
echo -e "MAX = $max\tMIN = $min"
