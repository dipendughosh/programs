read -p "Enter x of the 1st coordinate: " x1
read -p "Enter y of the 1st coordinate: " y1
read -p "Enter x of the 2nd coordinate: " x2
read -p "Enter y of the 2nd coordinate: " y2
read -p "Enter x of the 3rd coordinate: " x3
read -p "Enter y of the 3rd coordinate: " y3
dy1=`expr $y2 - $y1`
dx1=`expr $x2 - $x1`
m1=`expr $dy1 / $dx1`
dy2=`expr $y3 - $y2`
dx2=`expr $x3 - $x2`
m2=`expr $dy2 / $dx2`
if [ $m2 -eq $m1 ]
then
	echo "The points are co-linear,cant make triangle."
else
	a=`echo "($x2-$x1)*($x2-$x1)+($y2-$y1)*($y2-$y1)"|bc`
	a=`echo "sqrt($a)"|bc`
	b=`echo "($x3-$x1)*($x3-$x1)+($y3-$y1)*($y3-$y1)"|bc`
	b=`echo "sqrt($b)"|bc`
	c=`echo "($x3-$x2)*($x3-$x2)+($y3-$y2)*($y3-$y2)"|bc`
	c=`echo "sqrt($c)"|bc`
	if [ $a -ne $b ]
	then
		if [ $a -ne $c ]
		then
			echo "the points form a scaling tringle."
		else
			echo "the points form a isoscale tringle."
		fi
	elif [ $a -eq $b ]
	then
		if [ $a -ne $c ]
		then 
			echo "the points form a isoscale tringle."
		else
			echo "the points form a equilateral tringle."
		fi
	fi
fi

