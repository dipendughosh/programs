i=0
while read t
do
	x=($t)
	if [ $i -eq 0 ]
	then
		z=`echo ${x[0]}`
		i=1
	elif [ $i -eq 1 ]
	then
		a=`echo ${x[6]}`
		b=`date +%D|cut -d / -f 2`
		if [ "$a" == "$b" ]
		then
			y=`echo ${x[7]}`
			s1=`date -d "$y" +%S`
			m1=`date -d "$y" +%M`
			h1=`date -d "$y" +%H`
			s2=`date +%S`
			m2=`date +%M`
			h2=`date +%H`
			s=`expr $s2 - $s1`
			m=`expr $m2 - $m1`
			h=`expr $h2 - $h1`
			if [ $s -lt 0 ]
			then
				s=`expr $s + 60`
				m=`expr $m - 1`
			fi
			if [ $m -lt 0 ]
			then
				m=`expr $m + 60`
				h=`expr $h - 1`
			fi
			if [ $h -lt 0 ]
			then
				h=`expr $h + 24`
			fi
			if [ $m -lt 10 ]
			then
				echo $z
			fi
		fi
		i=0
	fi
done<last.txt
