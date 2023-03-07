# no of interval shoud pass as argument
while true
do
	c=`who|wc -l`
	col=`tput cols`
	s=`expr $col - 18`
	tput $c
	tput cup 0 $s
	tput rev
	echo "no of user $c"
	tput sgr0
	tput c
	sleep $1m
done


#ok
