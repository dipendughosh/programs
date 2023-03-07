read -p "Enter range : - " n
if [ $n -eq 1 ]
then
	echo "Entered number is 1"
	exit
fi
echo -e "The prime numbers till $n are \t"
for i in `seq 2 $n`
do
	x=0
	for j in `seq $i`
	do
		y=`expr $i % $j`
		if [ $y -eq 0 ]
		then
			x=`expr $x + 1`
		fi
	done
	if [ $x -eq 2 ]
	then
		echo -e "$i \t"
	fi
done
