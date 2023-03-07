read -p "Enter input base :- " ib
read -p "Enter output base :- " ob
read -p "Enter number in the input base :- " num
n=$num
i=0
z=0
while [ $n -ne 0 ]
do
	a=`expr $n % 10`
	if [ $a -ge $ib ]
	then
		echo "Wrong entry"
		exit
	fi
	x=`echo $ib^$i|bc`
	y=`expr $x \* $a`
	z=`expr $z + $y`
	n=`expr $n / 10`
	i=`expr $i + 1`
done
y=""
while [ $z -ne 0 ]
do
	x=`expr $z % $ob`
	y=$x$y
	z=`expr $z / $ob`
done	
echo -e "Number = $num\nInput Base = $ib\nOutput Base = $ob\nConverted number = $y"

