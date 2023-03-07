if [ $# -eq 0 ]
then 
	echo "Error:no such file"
	read -p "Give the name of the file" fn
else
	fn=$1
fi

if [ -f "$fn" ]
then 
	str= "$fn is a file that is" 
  	if [ -r "$fn" ]
	then
		str="$str readable"
	fi
	if [ -w "$fn" ]
	then
		str="$str writable"
  	fi
	if [ -x "$fn" ]
  	then 
		str="$str executable"
	fi
elif [ -d "$fn" ]
then 
	str="$fn is a directory"
else
	str="$fn does not exist"
fi
echo $str