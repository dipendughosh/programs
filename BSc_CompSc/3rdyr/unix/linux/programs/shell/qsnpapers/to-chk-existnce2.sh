echo -e "For one single argument(if not found exit enter name)\n"
if [ $# -eq 0 ]
then
	echo "Error:No file name entered"
	read -p "Enter name of file:- " fn
elif [ $# -gt 1 ]
then
	echo "Error:Extra file name entered"
	exit
else
	fn=$1
fi

if [ -f "$fn" ]
then
	str="$fn is a file that is:"
	if [ -r "$fn" ]
	then
		str="$str Readable"
	fi
	if [ -w "$fn" ]
	then
		str="$str Writeable"
	fi
	if [ -x "$fn" ]
	then
		str="$str Executible"
	fi
	if [ -s "$fn" ]
	then
		s=`ls -l $fn|cut -d " " -f 5`
		str="$str size is $s"
	else
		str="$str size is 0"
	fi
	s=`ls -l $fn|cut -d " " -f 6`
	str="$str created on $s"
	s=`ls -l $fn|cut -d " " -f 7`
	str="$str at $s"
elif [ -d "$fn" ]
then
	str="$fn is a Directory"
else
	str="$fn Does not exists"
fi
echo -e "\n$str"
