while true
do
	x=`date +%I:%M:%S%p`
	len=`expr length $x`
	col=`tput cols`
	c=`expr $col - $len`
	tput sc
	tput cup 1 $c
	tput rev
	echo $x
	tput sgr0
	tput rc
	sleep 1s
done
