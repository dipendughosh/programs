if [ $# -ne 1 ]
then
	echo "ERROR"
	exit
fi
l=`expr length $1`
i=0
f=0
while [ $i -le $l ]
do
	x=`expr substr "$1" $i 1`
	z=`echo $x|grep [aeiou] -c`
	if [ $z -eq 1 ]
	then
		f=1
	fi
	i=`expr $i + 1`
done
if [ $f -eq 1 ]
then
	echo "VOWEL PRESENT"
fi
