function prime()
{
	t=$1
	x=0
	for i in `seq $t`
	do
		y=`expr $1 % $i`
		if [ $y -eq 0 ]
		then
			x=`expr $x + 1`
		fi
	done
	if [ $x -eq 2 ]
	then
		x=1
	else
		x=0
	fi
	echo $x
}
read -p "Enter number whose prime factors are to be found:- " n
echo "The prime factors of $n are-"
for i in `seq 2 $n`
do
	x=`expr $n % $i`
	if [ $x -eq 0 ]
	then
		x=`prime $i`
		if [ $x -eq 1 ]
		then
			printf "\t%d" $i
		fi
	fi
done
echo " "
