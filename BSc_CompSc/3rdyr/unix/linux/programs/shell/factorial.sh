function fact()
{
	f=1
	for i in `seq $n`
	do
		f=`expr $f \* $i`
	done
	echo $f
}	
read -p "Enter number of for whose factorial is to be found : " n
f=`fact $n`
echo "Factorial of $n = $f"
