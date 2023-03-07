if [ $# -eq 0 ]
then
	echo "Error:- No line entered"
	exit
fi
x=$*
read -p "Enter the file name: " n
echo $x|cat>>$n 
