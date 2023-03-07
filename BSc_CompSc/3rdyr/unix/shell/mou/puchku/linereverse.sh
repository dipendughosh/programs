read -p "Enter the file name: " n
read -p "Enter the destination file: " m
c=1
l=`wc -l $n`
while [ $l -gt 0 ]
do
	s=`expr tail -n $n|head 1`
	c=`expr $c + 1`
	l=`expr $l - 1`
	echo $s |cat>>$m
done



