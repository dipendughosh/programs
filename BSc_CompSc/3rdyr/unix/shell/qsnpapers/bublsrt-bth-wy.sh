read -p "Enter size of array :- " n                                                 
echo -e "Enter elements of the array \t"                                            

t=`expr $n - 1`
for i in `seq 0 $t`
do                 
        read -p "a[$i] = " a[$i]
done                            

echo "The entered array is:"
for i in `seq 0 $t`
do
        echo "a[$i] = " ${a[$i]}
done
read -p "Enter 1 for Ascending and 2 for Descending order sort:- " c
case $c in
	'1')	i=0
		while [ $i -lt $t ]
		do
        		j=0
		        y=`expr $t - $i`
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
		;;
	'2')	i=0
		while [ $i -lt $t ]
		do
        		j=0
		        y=`expr $t - $i`
        		while [ $j -lt $y ]
	        	do
        	        	x=`expr $j + 1`
	                	if [ ${a[$j]} -lt ${a[$x]} ]
		                then
        		                l=${a[$j]}
                		        a[$j]=${a[$x]}
                        		a[$x]=$l
		                fi
        		        j=`expr $j + 1`
	        	done
	        	i=`expr $i + 1`
		done
		;;
	esac

echo "The sorted array is:"
for i in `seq 0 $t`
do
        echo "a[$i] = " ${a[$i]}
done
