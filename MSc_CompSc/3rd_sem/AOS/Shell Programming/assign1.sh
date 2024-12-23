src="Employee_list.txt"

#ID/NAME/DESIGNATION/DATE-OF-BIRTH/BASIC-PAY/DEPARTMENT 

echo -e "\tMENU"
echo -e "1.Sort"
echo -e "2.Departments"
echo -e "3.Persons in each department"
echo -e "4.Create pay slip"
echo -e "5.Gross salary in each department"
echo -e "6.Persons born this month"
echo -e "7.Exit"
read -p "Enter choice:- " ch

case $ch in
        '1')
	    sort -t"/" -k 4 -k 3 -k 2 $src -o temp.txt	
	    echo -v"/" | cat temp.txt
	    rm temp.txt
	;;
        '2')
	    sort -u -t"/" -k 6 $src | cut -d"/" -f 6
	;;
        '3')
	    sort -t"/" -k 6 $src | cut -d"/" -f 6 | uniq -c
	;;
        '4')
	    noln=`wc $src -l | cut -d" " -f 1`
	    i=1;
	    dst="Pay_Slip.txt"
	    #echo "NAME|DEPT|Basic|DA|HRA|PF|GROSS"|cat>>$dst
	    while [ $i -le $noln ]
	    do
	        bp=`head -n $i $src | tail -n 1 | cut -d"/" -f 5`
	        da=`expr $bp \* 6`
	        da=`expr $da / 100`
	        hra=`expr $bp \* 15`
	        hra=`expr $hra / 100`
	        pf=`expr $bp \* 1`
	        pf=`expr $pf / 100`
	        gross=`expr $bp + $da + $hra - $pf`
	        name=`head -n $i $src | tail -n 1 | cut -d"/" -f 2`
	        dept=`head -n $i $src | tail -n 1 | cut -d"/" -f 6`
	        echo "$name / $dept / $bp / $da / $hra / $pf / $gross"|cat>>$dst
	        i=`expr $i + 1`
	    done
	;;
        '5')
	    dst="Pay_Slip.txt"
	    noln=`wc $dst -l | cut -d" " -f 1`
	    i=1;
	    while [ $i -le $noln ]
	    do
	        gs=`head -n $i $dst | tail -n 1 | cut -d"/" -f 7`
	        dept=`head -n $i $dst | tail -n 1 | cut -d"/" -f 2`
	        echo "$gs / $dept" | cat>>temp.txt
	        i=`expr $i + 1`
	    done
	    sort -t"/" -k 2 temp.txt | cat>>temp1.txt
	    temp=`sort -t"/" -k 2 temp.txt | cut -d"/" -f 2 | uniq -c`
	    echo "$temp" | cat>>temp2.txt
	    m=`wc temp2.txt -l | cut -d" " -f 1`
	    i=1
	    k=1
	    while [ $i -le $m ]
	    do
	        n=`head -n $i temp2.txt | tail -n 1 | cut -d" " -f 7`
	        j=1
	        tgs=0
	        while [ $j -le $n ]
	        do
		gs=`head -n $k temp1.txt | tail -n 1 | cut -d" " -f 2`
		tgs=`expr $tgs + $gs`
		k=`expr $k + 1`
		echo $k
		j=`expr $j + 1`
	        done
	        dept=`head -n $i temp2.txt | tail -n 1 | cut -d" " -f 11`
	        echo "$dept $tgs"
	        i=`expr $i + 1`
	    done
	    rm temp.txt
	    rm temp1.txt
	    rm temp2.txt
	;;
        '6')
	    m=`date +%m`
	    x=`wc $src -l | cut -d" " -f 1`
	    i=1
	    while [ $i -le $x ]
	    do
	        gs=`head -n $i $src | tail -n 1 | cut -d"/" -f 4`
	        echo "$gs" | cat>>temp3.txt
	        mn=`tail -n 1 temp3.txt | cut -d"-" -f2`
	        if [ $mn -eq $m ]
	        then
				name=`head -n $i $src | tail -n 1 | cut -d"/" -f 2`
				echo "$name" | cat>>birth.txt
	        fi
	        i=`expr $i + 1`
	    done
	    rm temp3.txt
	;;
        '7')
	    exit
	;;
        *)
	;;
esac