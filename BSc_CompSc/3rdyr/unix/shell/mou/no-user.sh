while true
do
	x=`date +%I`
	y=`date +%M`
	z=`date +%S%p`
	len1=`expr length $x`
	len2=`expr length $y`
	len3=`expr length $z`
	col=`tput cols`
	c=`expr $col - $len1 - $len2 - $len3 - 2`
	tput sc
	tput cup 0 $c
	tput rev
	echo $x
	c=`expr $c + $len1`
	tput cup 0 $c
	tput blink
	echo ":"
	tput sgr0
	c=`expr $c + 1`
	tput cup 0 $c
	tput rev
	echo $y
	c=`expr $c + $len2`
	tput cup 0 $c
	tput blink
	echo ":"
	tput sgr0
	c=`expr $c + 1`
	tput cup 0 $c
	tput rev
	echo $z
	tput sgr0
	n=`who|wc -l`
	col1=`tput cols`
	col1=`expr $col1 - 18`
	tput cup 1 $col1
	tput rev
	echo "No of users are " $n
	tput sgr0
	tput rc
	sleep 1s
done
