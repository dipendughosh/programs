if [ $# -lt 1 ]
then
	echo "ERROR:-<options> Filename"
	exit
elif [ $# -gt 4 ]
then
	echo "ERROR:-<options> Filename"
	exit
fi
a=$*
x=`echo "$a"|wc -w`
for i in $a
do
	x=`expr $x - 1`
	if [ $x -ne 0 ]
	then
		len=`expr length $i`
		y=`expr substr $i 1 1`
		if [ $y == '-' ]
		then
			str=$str$y
			z=`expr substr $i 2 1`
			if [ $z == 'o' ]
			then
				str=$str'c'
			elif [ $z == 'b' ]
			then
				str=$str'l'
			elif [ $z == 'w' ]
			then
				str=$str$z
			else
				echo "Wrong Option" $z
				exit
			fi
		else
		       echo "Wrong Format- no '-'"	
		       exit
	       fi
       else
	       str=$str$i
       fi
       str=$str' '
done
echo `wc $str`
