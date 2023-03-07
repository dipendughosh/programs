if [ $# -eq 0 ]
then
	echo "ERROR:Too less arguments"
	exit
fi
for i in `seq 1 20`
do
	a[$i]=0
done

while read t
do
	for i in $t
	do
		if [ $i != " " ]
		then
			x=`expr length $i`
			a[$x]=`expr ${a[$x]} + 1`
		fi
	done
done<$1

echo -e "The number of words of different lengths are:-\nLength\tFrequency"
for i in `seq 1 20`
do
	echo -e "$i\t${a[$i]}"
done

