if [ $# -eq 0 ]
then
	echo "Error:No file name entered"
	exit
fi
echo -e "File or not"
test -f $1
f=`echo $?`
if [ $f -eq 0 ]
then
	echo -e "\nFile"
else
	echo -e "\nNot File"
fi

echo -e "Directory or not"
test -d $1
f=`echo $?`
if [ $f -eq 0 ]
then
	echo -e "\nDirectory"
else
	echo -e "\nNot Directory"
fi

echo -e "Executible or not"
test -x $1
f=`echo $?`
if [ $f -eq 0 ]
then
	echo -e "\nExecutible"
else
	echo -e "\nNot Executible"
fi

echo -e "Readable or not"
test -r $1
f=`echo $?`
if [ $f -eq 0 ]
then
	echo -e "\nReadable"
else
	echo -e "\nNot Readable"
fi

echo -e "Writeable or not"
test -w $1
f=`echo $?`
if [ $f -eq 0 ]
then
	echo -e "\nWriteable"
else
	echo -e "\nNot Writeableble"
fi

echo -e "Size Zero or not"
test -s $1
f=`echo $?`
if [ $f -eq 0 ]
then
	echo -e "\nSize Not Zero"
else
	echo -e "\nSize Zero"
fi
