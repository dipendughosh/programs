if [ $# -lt 2 ]
then
	echo "Error:-"
	exit
elif [ $# -gt 4 ]
then
	echo "Error:-"
	exit
fi
if [ $# -eq 4 ]
then
	fn=$4
elif [ $# -eq 3 ]
then
	fn=$3
elif [ $# -eq 2 ]
then
	fn=$2
fi
l=0
c=0
w=0
z=" "
while read t
do
	l=`expr $l + 1`
	x=`expr length "$t"`
	c=`expr $x + $c + 1`
	x=($t)
	y=${#x[*]}
	w=`expr $w + $y`  
done<$fn
x=$#
y=$*
for i in $y
do
	case $i in
		'-l')
			printf "%d\t" $l	
			;;
		'-w')
			printf "%d\t" $w
			;;
		'-c')
			printf "%d\t" $c
			;;
	esac
	x=`expr $x - 1`
	if [ $x -eq 1 ]
	then
		break
	fi
done
echo ""
