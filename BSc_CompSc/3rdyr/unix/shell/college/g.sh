if [ $# -eq 0 ]
then
	echo "ERROR :- No data file entered"
	exit
fi
x="temp.txt"
echo -e "Person_id\tTotal Earning\tIncome Tax"|cat>$x
while read t
do
	a=($t)
	s=`expr ${a[1]} + ${a[2]} + ${a[3]}`
	if [ $s -lt 50000 ]
	then
		r1=0
		r2=0
	elif [ $s -ge 50000 ]
	then
		if [ $s -lt 90000 ]
		then
			r1=20
			r2=0
		fi
	elif [ $s -ge 90000 ]
	then
		if [ $s -lt 150000 ]
		then
			r1=30
			r2=0
		fi
	else
		r1=30
		r2=10
	fi
	tx=`echo "($s*$r1/100)"|bc`
	t=`echo "($tx*$r2/100)"|bc`
	tx=`expr $tx + $t`
	if [ $tx -eq 0 ]
	then
		tx=NIL
	fi
	echo -e "${a[0]}\t\t$s\t\t$tx"|cat>>$x		
done<$1

