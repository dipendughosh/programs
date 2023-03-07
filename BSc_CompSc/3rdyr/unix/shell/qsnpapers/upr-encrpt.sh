if [ $# -eq 0 ]
then
	echo "ERROR"
	exit
fi
n=$*
for i in $n
do
	while read t
	do
		x=`echo "$t"|tr 'a-z' 'A-Z'`
		echo $x|cat>>temp.txt
	done<$i
	mv temp.txt $i
	cat $i
	while read t
	do
		x=`echo "$t"|tr 'A-Z' 'B-ZA'`
		echo $x|cat>>temp.txt
	done<$i
	mv temp.txt $i
	cat $i
done

