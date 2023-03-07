if [ $# -eq 0 ]
then
	read -p "Give file name : " fn
else
	fn=$1
fi
ls $fn 1>/dev/null 2>/dev/null
if [ $? -eq 0 ]
then
	echo "Found : " $fn
else
	echo "Not Found : " $fn
fi
