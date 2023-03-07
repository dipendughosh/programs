if [ $# -eq 0 ]
then
	echo "Error:-No files entered"
	exit
fi
i=$#
i=`expr $# % 2`
if [ $i -ne 0 ]
then
	echo "Odd number of files entered"
	exit
fi
str=($*)
i=0
while [ $i -lt $# ]
do
	j=`expr $i + 1`
	cp ${str[$i]} ${str[$j]}
	i=`expr $i + 2`
done
