read -p "Give the number: " n
c=0
for i in `seq $n`
do 
	d=`expr $n % $i`
	if [ $d -eq 0 ]
		c=`expr $c + 1`
	fi
done
if [ $c -eq 2 ]
	echo "this is a prime no."
else 
	echo "this is a non-prime number."
fi

echo te % nae kina janina eta try koris