function sum1()
{
	t=`expr $n1 + $n2`
	return $t
}
read -p "First No. : " n1
read -p "Second no. : " n2
sum1 $n1 $n2
echo "Sum is : " $?

function sum2()
{
	t=`expr $1 + $2`
	echo $t
}
read -p "First No. : " n1
read -p "Second no. : " n2
x=`sum2 $n1 $n2`
echo "Sum is : " $x
