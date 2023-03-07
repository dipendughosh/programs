if [ $# -eq 0 ]
then
	echo "ERROR"
	exit
fi
read -p "Enter from the column to cut:- " n
read -p "Enter to the column to cut:- " m
cut -b $n-$m $1

