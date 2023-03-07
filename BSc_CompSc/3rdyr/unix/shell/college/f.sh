read -p "Enter number to check divisibility by 2 :- " n
x=`expr $n % 2`
if [ $x -eq 0 ]
then
	echo $n "is divisible by 2"
else
	echo $n "is not divisible by 2"
fi
