read -p "Enter size of 1st array :- " n1
echo -e "Enter elements of 1st array in sorted order:-"
n1=`expr $n1 - 1`
for i in `seq 0 $n1`
do
	read -p "a[$i] = " a[$i]
done
read -p "Enter size of 2nd array :- " n2
echo -e "Enter elements of 2nd array in sorted order:-"
n2=`expr $n2 - 1`
for i in `seq 0 $n2`
do
	read -p "b[$i] = " b[$i]
done
n3=`expr $n1 + $n2 + 1`
i=0
j=0
k=0
while [ $i -le $n3 ] 
do
	if [ ${a[$j]} -eq ${b[$k]} ]
	then
		c[$i]=${a[$j]}
		i=`expr $i + 1`
		j=`expr $j + 1`
		c[$i]=${b[$k]}
		i=`expr $i + 1`
		k=`expr $k + 1`
	elif [ ${a[$j]} -lt ${b[$k]} ]
	then
		c[$i]=${a[$j]}
		i=`expr $i + 1`
		j=`expr $j + 1`
	elif [ ${b[$k]} -lt ${a[$j]} ]
	then
		c[$i]=${b[$k]}
		i=`expr $i + 1`
		k=`expr $k + 1`
	fi
	if [ $j -gt $n1 ]
	then
		break
	fi
	if [ $k -gt $n2 ]
	then
		break
	fi
done
if [ $j -le $n1 ]
then
	while [ $j -le $n1 ]
	do
		c[$i]=${a[$j]}
		i=`expr $i + 1`
		j=`expr $j + 1`
	done
fi
if [ $k -le $n2 ]
then
	while [ $k -le $n2 ]
	do
		c[$i]=${b[$k]}
		i=`expr $i + 1`
		k=`expr $k + 1`
	done
fi
echo -e "Diplaying the merged array:-"
for i in `seq 0 $n3`
do
	echo -e "c[$i] = " ${c[$i]}
done
