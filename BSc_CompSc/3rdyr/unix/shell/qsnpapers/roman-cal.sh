x=`date +%Y`
read -p "Enter month in roman:- " n
n=`echo $n|tr 'A-Z' 'a-z'`
case $n in
	'i')cal 1 $x
	;;
	'ii')cal 2 $x
	;;
	'iii')cal 3 $x
	;;
	'iv')cal 4 $x
	;;
	'v')cal 5 $x
	;;
	'vi')cal 6 $x
	;;
	'vii')cal 7 $x
	;;
	'viii')cal 8 $x
	;;
	'ix')cal 9 $x
	;;
	'x')cal 10 $x
	;;
	'xi')cal 11 $x
	;;
	'xii')cal 12 $x
	;;
	*)echo "Wrong Choice"
	;;
esac
