read -p "Give the limit: " m
if [ $m -eq 1 ]
then
	echo "Entered number is 1"
	exit
fi
echo "1"
n=1
while [ $n -le $m ]
do
	c=0
	for i in `seq $n`
	do 
		d=`expr $n % $i`
		if [ $d -eq 0 ]
		then
			c=`expr $c + 1`
		fi
	done
	if [ $c -eq 2 ]
	then
		echo $n
	fi
	n=`expr $n + 1`
done
