read -p "Write the no. of employee:" n
i=1
while [ $i -le $n ]
do
	read -p "Give the id of the person:" i
	read -p "Give the salary of the person:" s
	read -p "Give the ammount of DA:" da
	read -p "Give the ammount of HRA:" hra
	sa1=`expr  $s + $da`
	sa=`expr $sa1 + $hra`
	if [ $sa -lt 50000 ]
	then
		echo "Income tax is nill"
	elif [ $sa -gt 50000 ]
	then
		if [ $sa -lt 90000 ]
		then 
			new=`echo "(20/100)*$sa"|bc`
			echo "Income tax is $new"
		fi
	elif [ $sa -gt 90000 ]
	then
		if [ $sa -lt 150000 ]
		then
			new=`echo "(30/100)*$sa"|bc`
			echo "Income tax is $new"
		fi
	elif [ $sa -gt 150000 ]
	then
		new=`expr $sa \* .3`
		new1=`expr $new \* .1`
		echo "Income tax is $new1"
	fi
	i=`expr $i + 1`
done



