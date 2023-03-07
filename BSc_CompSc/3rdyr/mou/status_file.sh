read -p "Give the name of the file" fn
if [ $# -eq 0 ]
then 
	echo "Error:no such file"
fi

if [ -f "fn" ]
then 
	str= "fn is" 
  if [ -r "$1" ]
  then
	str="$str readable"
  fi
  if [ -w "fn" ]
  then
	str="$str writable"
  fi
  if [ -x "fn" ]
  then 
	str="$str executable"
  fi
	echo "$str file.."
elif [ -d "fn" ]
then 
	echo "fn is a directory"
else
	echo "fn does not exist"
fi


