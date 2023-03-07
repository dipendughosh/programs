read -p "Enter a number:- " n
read -p "Enter a number:- " m
if [ $n -eq 1 -o $m -eq 1 ]
then
	echo "A"
elif [ $n -eq 0 ]
then
	echo "C"
else
	echo "B"
fi

