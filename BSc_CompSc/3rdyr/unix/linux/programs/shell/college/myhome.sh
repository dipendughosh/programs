if [ $# -eq 0 ]
then
	echo "ERROR:-No file entered"
	exit
fi
y=0
a=$*
for i in $a
do
	test -f $i
	f=`echo $?`
	if [ $f -eq 0 ]
	then
		l=`wc -l $i`
		w=`wc -c $i`
		s=`ls -l $i|cut -d" " -f5`
		echo "size : $s words : $w lines : $l"
		y=1
	else 
		test -d "myhome"
		h=`echo $?`
		if [ $h -eq 0 ]
		then
			cd myhome
			x=`ls -l|wc -l`
			echo "myhome exists and number of files in it are : $x"
			break
		fi
	fi
done
if [ $y -eq 0 ]
then
	mkdir myhome
	for i in $a
	do
		cd myhome
		touch $i
		cd ..
	done
fi

