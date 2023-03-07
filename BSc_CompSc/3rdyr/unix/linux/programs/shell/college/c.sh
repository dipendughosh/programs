if [ $# -eq 0 ]
then
	echo "Error :- too few arguments"
	exit
fi
b=($*)
i=`expr $# - 1`
while [ $i -ge 0 ]
do
	printf "%s " ${b[$i]}
	i=`expr $i - 1`
done

