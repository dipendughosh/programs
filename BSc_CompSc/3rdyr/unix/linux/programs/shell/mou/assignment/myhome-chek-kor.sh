if [ $# -eq 0 ]
then
	echo "ERROR:-No file entered"
fi
a=$*
for i in $a
do
	test -f $i
	f=`echo $?`
	if [ $f -eq 0 ]
	then
		l=`echo wc -l $i`
		w=`echo wc -c $i`
		s=`echo ls -l $i|cut -d" " -f5`
		echo "size of the file is $s"
		echo "word in the file is $w"
		echo "line in the file is $l"
	else
		test -d "myhome"
		h=`echo $?`
		if [ $f -eq 1 ]
		then
			mkdir "myhome"
			touch $i
		else
			cd "myhome"
			 no of file
		 fi
	 fi
 done


