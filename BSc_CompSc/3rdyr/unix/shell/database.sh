src="data.txt"
echo -e "\tMENU"
echo -e "1.Create"
echo -e "2.New Entry"
echo -e "3.Edit Entry"
echo -e "4.Delete Entry"
echo -e "5.Sort"
echo -e "6.Exit"
read -p "Enter choice:- " ch
case $ch in
	'1')	
		echo "ID|NAME|DESIG|PH NO|SAL"|cat>>$src
		while true
		do
			read -p "Enter id :- " id
			read -p "Enter name :- " name
			read -p "Enter designation :- " desig
			read -p "Enter phone number :- " phno
			read -p "Enter salary :- " sal
			echo "$id | $name | $desig | $phno | $sal"|cat>>$src
			read -p "Do you want to enter more?(Y/y) " c
			if [ $c != 'y' ]
			then
				if [ $c != 'Y' ]
				then
					break
				fi
			fi
		done
		;;
	'2')
		read -p "Enter id :- " id
		read -p "Enter name :- " name
		read -p "Enter designation :- " desig
		read -p "Enter phone number :- " phno
		read -p "Enter salary :- " sal
		echo "$id | $name | $desig | $phno | $sal"|cat>>$src
		;;
	'3')
		touch temp.txt
		x=0
		f=0
		read -p "Enter id for which to edit:- " eid
		while read t
		do
			f=0
			y=`echo "$t"|cut -d'|' -f1`
			if [ $y !=  $eid ]
			then
				echo "$t"|cat>>temp.txt
			else
				echo "xxxx"
				scanf "%s" id
				read name
				read desig
				read phno
				read sal
				echo -e "\n$id | $name | $desig | $phno | $sal"|cat>>temp.txt
				x=1
				f=0
			fi
		done<$src
		if [ $x -eq 1 ]
		then
			mv temp.txt $src
		fi
		;;
	'4')
		read -p "Enter id for which to delete:- " eid
		while read t
		do
			echo $t
			for i in $t
			do
				if [ "$i" == "$eid" ]
				then
					f=1
					break
				else
					f=0
					break
				fi
			done
			if [ $f -eq 0 ]
			then
				echo "$t"|cat>>temp.txt
			fi
		done<$src
		mv temp.txt $src
		;;
	'5')
		sort -n -r -t'|' -k5 $src -o temp.txt	
		;;
	'6')
		exit
		;;
	*)
	;;
esac
		

