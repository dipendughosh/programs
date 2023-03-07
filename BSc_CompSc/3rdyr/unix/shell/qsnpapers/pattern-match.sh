if [ $# -eq 0 ]
then
	echo "ERROR"
	read -p "Enter file name:- " fn
	read -p "Enter pattern to search:- " pm
else
	fn=$1
	pm=$2
fi
l=`wc -l $fn|cut -b 1`
m=`echo "$l/2"|bc`
echo $m
i=1
x=0
len1=`expr length $pm`
while read t
do
	len2=`expr length "$t"`
	j=1
	while [ $j -lt $len2 ]
	do
		sub=`expr substr "$t" $j $len1`
		if [ "$sub" == "$pm" ]
		then
			x=`expr $x + 1`
			if [ $i -eq 0 ]
			then
				echo "Present at the begining"
			fi
			if [ $i -eq $l ]
			then
				echo "Present at the end"
			fi
			if [ $i -eq $m ]
			then
				echo "Present at middle"
			fi
		fi
		j=`expr $j + 1`
	done
	i=`expr $i + 1`
done<$fn
echo "$pm Present $x Number of times"

