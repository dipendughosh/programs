read -p "Enter a string:- " str
echo "Displaying individual charaters:-"
l=`expr length "$str"`
for i in `seq 0 $l`
do
	s=`expr substr "$str" $i 1`
	echo $s
done
