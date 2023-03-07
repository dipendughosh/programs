read -p "Enter size of array :- " n
echo -e "Enter elements of the array \t"

t=`expr $n - 1`
for i in `seq 0 $t`
do
	read -p "a[$i] = " a[$i]
done

read -p "Enter element to search from the given array :- " no

f=0
i=0
while [ $i -le $t ]
do
	if [ ${a[$i]} -eq $no ]
	then
		f=1
		echo $no" found at position " $i
			break
	fi
	i=`expr $i + 1`
done
if [ $f -eq 0 ]
then
	echo $no" not found"
fi
