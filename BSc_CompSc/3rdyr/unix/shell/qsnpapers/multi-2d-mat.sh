echo "For 1st number"
read -p "Enter number of rows of the matrix :- " n1
read -p "Enter number of columns of the matrix :- " m1
k=0
n1=`expr $n1 - 1`
m1=`expr $m1 - 1`
for i in `seq 0 $n1`
do
	for j in `seq 0 $m1`
	do
		read -p "a[$i][$j] = " a[$k]
		k=`expr $k + 1`
	done
done
echo "For 2nd number"
read -p "Enter number of rows of the matrix :- " n2
read -p "Enter number of columns of the matrix :- " m2
k=0
n2=`expr $n2 - 1`
m2=`expr $m2 - 1`
for i in `seq 0 $n2`
do
	for j in `seq 0 $m2`
	do
		read -p "b[$i][$j] = " b[$k]
		k=`expr $k + 1`
	done
done
if [ $m1 -ne $n2 ]
then
	exit
fi
k=0
for i in `seq 0 $n1`
do
	for j in `seq 0 $m2`
	do
		c[$k]=0
		k=`expr $k + 1`
	done
done
for i in `seq 0 $n1`
do
	for j in `seq 0 $m2`
	do
		for k in `seq 0 $m1`
		do
			x=`expr $m2 + 1`
			x=`expr $i \* $x`
			x=`expr $x + $j`
			y=`expr $m1 + 1`
			y=`expr $i \* $y`
			y=`expr $y + $k`
			z=`expr $m2 + 1`
			z=`expr $k \* $z`
			z=`expr $z + $j`
			echo $i $j $k $x $y $z
			d=`expr ${a[$y]} \* ${b[$z]}`
			c[$x]=`expr ${c[$x]} + $d`
		done
	done
done
k=0
echo "1st array"
for i in `seq 0 $n1`
do
	for j in `seq 0 $m1`
	do
		printf "a[%d][%d]=%d\t" $i $j ${a[$k]}
		k=`expr $k + 1`
	done
	echo ""
done
k=0
echo "2nd array"
for i in `seq 0 $n2`
do
	for j in `seq 0 $m2`
	do
		printf "b[%d][%d]=%d\t" $i $j ${b[$k]}
		k=`expr $k + 1`
	done
	echo ""
done
k=0
echo "3rd array"
for i in `seq 0 $n1`
do
	for j in `seq 0 $m2`
	do
		printf "c[%d][%d]=%d\t" $i $j ${c[$k]}
		k=`expr $k + 1`
	done
	echo ""
done
