read -p "Enter the range :- " n
a=0
b=1
echo -e "$a \n$b"
for i in `seq 3 $n`
do
	c=`expr $a + $b`
	echo $c
	a=$b
	b=$c
done
