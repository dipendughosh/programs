ls $1 1>/dev/null 2>/dev/null
if [ $? -eq 0 ]
then
	echo "Found :" $1
else
	echo "Not Found : " $1
fi
