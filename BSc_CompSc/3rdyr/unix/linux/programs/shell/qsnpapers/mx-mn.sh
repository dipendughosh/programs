read -p "Enter the no of elements: " n
read -p "Enter the 1st element: " j
h=l=$j
n=`expr $n - 1`
for i in `seq $n`
do
	read -p "Enter element: " m
	if [ $m -gt $h ]
	then
		h=$m
	elif [ $m -le $l ]
	then 
		l=$m
	fi
done
echo "The max no. is "$h.
echo "The min no. is "$l.


