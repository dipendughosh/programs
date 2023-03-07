echo "For one single argument(if not found exit)\n"
if [ $# -eq 0 ]
then
	echo "Error:No file name entered"
	exit
elif [ $# -gt 1 ]
then
	echo "Error:Extra file name entered"
	exit
fi

if [ -f "$1" ]
then
	str="$1 is a file that is:"
	if [ -r "$1" ]
	then
		str="$str Readable"
	fi
	if [ -w "$1" ]
	then
		str="$str Writeable"
	fi
	if [ -x "$1" ]
	then
		str="$str Executible"
	fi
	if [ -s "$1" ]
	then
		s=`ls -l $1|cut -d " " -f 5`
		str="$str size is $s"
	else
		str="$str size is 0"
	fi
	s=`ls -l $1|cut -d " " -f 6`
	str="$str created on $s"
	s=`ls -l $1|cut -d " " -f 7`
	str="$str at $s"
elif [ -d "$1" ]
then
	str="$1 is a Directory"
else
	str="$1 Does not exists"
fi
echo -e "\n$str"
