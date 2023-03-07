x=`date +%Y`
if [ $# -eq 0 ]
then
	y=`date +%B`
	echo $y $x
elif [ $# -eq 1 ]
then
	cal $1 $x

else
	n=$*
	for i in $n
	do
		cal $i $x
	done
fi

