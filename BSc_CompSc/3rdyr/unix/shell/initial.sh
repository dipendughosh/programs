read -p "Enter name:- " str1

n=`echo "$str1"|wc -w`
for i in $str1
do
	n=`expr $n - 1`
	if [ $n -ne 0 ]
	then
		str="$str `expr substr "$i" 1 1`."
	else
		str="$str $i"
	fi
done 
echo $str
