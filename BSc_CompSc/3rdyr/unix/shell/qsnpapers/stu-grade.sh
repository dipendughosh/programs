if [ $# -ne 1 ]
then
	echo "ERROR:-"
	exit
fi
while read t
do
	a=($t)
	x=`expr ${a[1]} + ${a[2]} + ${a[3]} + ${a[4]}`
	x=`expr $x / 4`
	if [ $x -ge 80 ]
	then
		g=O
	elif [ $x -ge 70 ]
	then
		if [ $x -le 79 ]
		then
			g=A
		fi
	elif [ $x -ge 60 ]
	then
		if [ $x -le 69 ]
		then
			g=B
		fi
	elif [ $x -ge 50 ]
	then
		if [ $x -le 59 ]
		then
			g=C
		fi
	elif [ $x -ge 40 ]
	then
		if [ $x -le 49 ]
		then
			g=D
		fi
	else
		g=Suppliment
	fi
	echo -e "${a[0]}\t$g"
done<$1



