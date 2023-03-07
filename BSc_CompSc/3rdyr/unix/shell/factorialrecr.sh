function fact()
{
	if [ $n -eq 0 ]
	then
		echo 1
	else
		n=`expr $n - 1`
		f=`fact $n`
		v=`expr $f \* $1`
		echo $v
	fi

}
read -p "Give number : " n
f=`fact $n`
echo "Factorial of $n = " $f
