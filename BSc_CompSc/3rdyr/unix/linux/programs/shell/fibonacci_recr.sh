function fibo()
{
	if [ $n -eq 0 ]
	then
		return
	else
		n=`expr $n - 1`
		d=`expr $a + $b`
		a=$b
		b=$d
		echo $d
		fibo $a $b $n
	fi
}
read -p "Enter number of terms:- " n
a=0
b=1
echo $a
echo $b
n=`expr $n - 2`
fibo $a $b $n
