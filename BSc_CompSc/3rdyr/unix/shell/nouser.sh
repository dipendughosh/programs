if [ $# -ne 1 ]
then
	echo "Error:-"
	exit
fi
while true
do
	n=`who|wc -l`
	col=`tput cols`
	col=`expr $col - 18`
	tput sc
	tput cup 0 $col
	tput rev
	echo "Number of USERS " $n
	tput sgr0
	tput rc
	sleep $1m
done

