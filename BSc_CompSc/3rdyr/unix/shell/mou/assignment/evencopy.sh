a=$# 
a=`expr $a - 1`
b=($*)
n=0

if [ $e -eq 0 ]
then
	while [ $n -lt $# ]
	do
		m=`expr $n + 1`
		cp ${b[$n]} ${b[$m]}
		n=`expr $n + 2`
	done
else
	echo "error"
fi
	
#error in else line
