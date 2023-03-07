while true
do
	read -p "Enter a positive integer:- " num
	if [ $num -lt 0 ]
	then
		echo "Re-Enter : -"
	else
		break
	fi
done
n=$num
while [ $n -ne 0 ]
do
	a=`expr $n % 10`
	y=$y$a
	n=`expr $n / 10`
done
echo "Reverse of $num is $y"		
