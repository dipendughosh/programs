read -p "Enter a string to check if pallindrome :- " str1

l=`expr length "$str1"`

i=$l
while [ $i -ge 0 ]
do
	str=`expr substr "$str1" $i 1`
	str2="$str2$str"
	i=`expr $i - 1`
done
if [ "$str1" == "$str2" ]
then
	echo "Pallindrome"
else
	echo "Not Pallindrome"
fi
