read -p "Enter the no: " n
for i in `seq $n`
do
	c=0
	r=`expr $n % $i`
	if [ $r -eq 0 ]
	then
		if [ $i -eq 1 ]
		then
			echo $i
		else
			for j in `seq $i`
			do
				x=`expr $i % $j`
				if [ $x -eq 0 ]
				then
					c=`expr $c + 1`
				fi
			done
			if [ $c -eq 2 ]
			then
				echo $i
			fi
		fi
	fi
done
