if [ $# -eq 0 ]
then
	echo "Error :- No sentence entered"
	exit
fi
x=$*
read -p "Enter a file name to append - " s
echo $x|cat>>$s
