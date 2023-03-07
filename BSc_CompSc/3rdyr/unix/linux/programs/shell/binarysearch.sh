read -p "Enter size of array :- " n
echo -e "Enter elements of the array \t"
t=`expr $n - 1`
for i in `seq 0 $t`
do
	read -p "a[$i] = " a[$i]
done

read -p "Enter element to search from the given array :- " no

i=0
while [ $i -lt $t ]
do
	j=0
	y=`expr $t - 1 - $i`
	while [ $j -lt $y ]
	do
		x=`expr $j + 1`
		if [ ${a[$j]} -gt ${a[$x]} ]
		then
			l=${a[$j]}
			a[$j]=${a[$x]}
			a[$x]=$l
		fi
		j=`expr $j + 1`
	done
	i=`expr $i + 1`
done

f=0
lw=0
hg=$t
while [ $lw -le $hg ]
do
	md=`echo "($lw+$hg)/2"|bc`
	if [ ${a[$md]} -eq $no ]
	then
		f=1
		n=`expr $md + 1`
		echo $no " found at " $n
		break
	elif [ ${a[$md]} -ge $no ]
	then
		hg=`expr $md - 1`
	else
		lw=`expr $md + 1`
	fi
done
if [ $f -eq 0 ]
then
	echo $no "not found"
fi

