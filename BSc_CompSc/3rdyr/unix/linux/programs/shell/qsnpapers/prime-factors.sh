function prime()
{
	t=$1
	x=0
	if [ $t -eq 1 ]
	then
		echo $t
		return
	fi
	for i in `seq $t`
	do
		z=`expr $t % $i`
		if [ $z -eq 0 ]
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
echo "The prime factors of $n are :- "
for i in `seq $n`
do
	y=`expr $n % $i`
	if [ $y -eq 0 ]
	then
		x=`prime $i`
		if [ $x -eq 1 ]
		then
			printf "%d\t" $i
		fi
	fi
done

