if [ $# -eq 0 ]
then
	echo "No arguments passed"
	exit
fi
n=$*
for i in $n
do
	x=`echo $i|tr 'a-z' 'A-Z'`
	case $x in
		'ONE')	tput bold
			;;
		'TWO')	tput rev
			;;
		'THREE')tput blink
			;;
		*)	echo "Wrong choice:- $i"
	esac
done
