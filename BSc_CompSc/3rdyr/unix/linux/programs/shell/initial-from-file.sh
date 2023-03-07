if [ $# -lt 2 ]
then
	echo "ERROR:Less argument:-"
	exit
fi
while read t
do
	n=`echo "$t"|wc -w`
	str='\0'
	for i in $t
	do
		n=`expr $n - 1`
		if [ $n -ne 0 ]
		then
			str="$str `expr substr "$i" 1 1`."
		else
			str="$str $i"
		fi
	done 
	echo -e "$str"|cat>>$2
done<$1
