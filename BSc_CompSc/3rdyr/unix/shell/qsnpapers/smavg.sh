read -p "Enter range n (20<= n <=50) :- " n
while [ 1 ]
do
	if [ $n -lt 20 ]
	then
		echo "RE-Enter"
		read n
	elif [ $n -gt 50 ]
	then
		echo "RE-Enter"
		read n
	else
		break
	fi
done
s=0
for i in `seq 1 $n`
do
	s=`expr $s + $i`
done
echo "Sum = $s"
s=`expr $s / $n`
echo "Average = $s"



