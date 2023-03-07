echo -e "Enter for 1st matrix:-"
read -p "Row:- " m1
read -p "Column:- " n1
m1=`expr $m1 - 1`
n1=`expr $n1 - 1`
k=0
for i in `seq 0 $m1`
do
	for j in `seq 0 $n1`
	do
		read -p "a[$i][$j] = " a[$k]
		k=`expr $k + 1`
	done
done

echo -e "Enter for 2nd matrix:-"
read -p "Row:- " m2
read -p "Column:- " n2
m2=`expr $m2 - 1`
n2=`expr $n2 - 1`
k=0
for i in `seq 0 $m2`
do
	for j in `seq 0 $n2`
	do
		read -p "b[$i][$j] = " b[$k]
		k=`expr $k + 1`
	done
done

if [ $n1 -ne $m2 ]
then
	echo "Not possible"
	exit
fi

k=0
for i in `seq 0 $m1`
do
	for j in `seq 0 $n1`
	do
		c[$k]=0
		k=`expr $k + 1`
	done
done

for i in `seq 0 $m1`
do
	for j in `seq 0 $n2`
	do
		for k in `seq 0 $m2`
		do
			x=`expr $n1 + 1`
			x=`expr $x \* $i`
			x=`expr $x + $j`
			y=`expr $n1 + 1`
			y=`expr $y \* $i`
			y=`expr $y + $k`
			z=`expr $m2 + 1`
			z=`expr $z \* $k`
			z=`expr $z + $j`
			d=`expr ${a[$y]} \* ${b[$z]}`
			c[$x]=`expr ${c[$x]} + $d`
		done
	done
done


echo -e "1st matrix:-"
k=0
for i in `seq 0 $m1`
do
	for j in `seq 0 $n1`
	do
		printf "%d\t" ${a[$k]}
		k=`expr $k + 1`
	done
	echo ""
done

echo -e "2nd matrix:-"
k=0
for i in `seq 0 $m2`
do
	for j in `seq 0 $n2`
	do
		printf "%d\t"  ${b[$k]}
		k=`expr $k + 1`
	done
	echo ""
done

echo -e "3rd matrix:-"
k=0
for i in `seq 0 $m1`
do
	for j in `seq 0 $n1`
	do
		printf "%d\t" ${c[$k]}
		k=`expr $k + 1`
	done
	echo ""
done
