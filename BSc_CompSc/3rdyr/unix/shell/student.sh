echo "ROLL|NAME|ENG|BEN|SSC|MTH"|cat>>stu.txt
while true
do
	read -p "Enter roll:- " roll
	read -p "Enter name :- " name
	read -p "Enter eng :- " eng
	read -p "Enter ben :- " ben
	read -p "Enter ssc :- " ssc
	read -p "Enter mth :- " mth
	echo "$roll | $name | $eng | $ben | $ssc | $mth"|cat>>stu.txt
	read -p "Do you want to enter more?(Y/y) " c
	if [ $c != 'y' ]
	then
		if [ $c != 'Y' ]
		then
			break
		fi
	fi
done
echo "ROLL|NAME|ENG|BEN|SSC|MTH|tot"|cat>>temp.txt
while read t
do
	x=`echo "$t"|cut -d'|' -f'3'`
	y=`echo "$t"|cut -d'|' -f'4'`
	z=`echo "$t"|cut -d'|' -f'5'`
	w=`echo "$t"|cut -d'|' -f'6'`
	tot=`expr $x + $y + $z + $w`
	echo "$t | $tot"|cat>>temp.txt
done<stu.txt
mv temp.txt stu.txt
sort -t'|' -k7 stu.txt>>temp.txt
mv temp.txt stu.txt
cat stu.txt
