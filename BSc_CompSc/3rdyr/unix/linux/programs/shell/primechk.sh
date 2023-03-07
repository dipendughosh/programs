read -p "Enter number : - " n
t=$n
x=0
for i in `seq $t`
do
	y=`expr $n % $i`
	if [ $y -eq 0 ]
	then
		x=`expr $x + 1`
	fi
done
if [ $x -eq 2 ]
then
	echo "PRIME"
else
	echo "NOT PRIME"
fi
