echo -e "\tMENU\n1.SUM\n2.DIFF\n3.Exit"
read -p "Enter choice :- " c
case $c in
	'1')	read -p "Enter 1st hex number:- " n1
		read -p "Enter 2nd hex number:- " n2
		n1=`echo $n1|tr 'a-f' 'A-B'`
		n2=`echo $n2|tr 'a-f' 'A-B'`
		n3=`echo "($n1+$n2)"|bc`
		printf "$n1 + $n2 = %X\n" $n3
		;;
	'2')	read -p "Enter 1st hex number:- " n1
		read -p "Enter 2nd hex number:- " n2
		n1=`echo $n1|tr 'a-f' 'A-B'`
		n2=`echo $n2|tr 'a-f' 'A-B'`
		n3=`echo "($n1-$n2)"|bc`
		printf "$n1 - $n2 = %X\n" $n3
		;;
	'3')	echo "Exiting..........."
		exit
		;;
	*)	echo "Wrong Choice"
		;;
esac
