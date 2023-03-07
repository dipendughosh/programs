if [ $# -eq 0 ]
then 
	echo "Error"
	exit
fi
w=`wc -w $1`
l=`wc -l $1`
c=`wc -c $1`
v=`wc -z $1`
echo "No of word is $w"
echo "No of length is $l"
echo "No of charector is $c"
echo "No of vowel is $v"
