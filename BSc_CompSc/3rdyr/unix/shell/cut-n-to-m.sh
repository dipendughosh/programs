if [ $# -lt 3 ]
then
	echo "ERROR:- <UpperBound> <LowerBound> <FileName>"
	read -p "Enter Upper Bound - " ub
	read -p "Enter Lower Bound - " lb
	read -p "Enter File Name - " fn
else
	ub=$1
	lb=$2
	fn=$3
fi
ub=`expr $lb - $ub + 1`
head -n $lb $fn|tail -n $ub
