echo -e "MENU"
echo -e "1.AAA\n2.BBB\n3.CCC\n4.EXIT"
read -p "Give choice : " ch
case $ch in
	'1')	echo "AAA"
		;;
	'2')	echo "BBB"
		;;
	'3')	echo "CCC"
		;;
	'4')	exit
		;;
	*)	echo "XXX"
		;;
esac

while true
do
	echo -e "MENU"
	echo -e "1.AAA\n2.BBB\n3.CCC\n4.EXIT"
	read -p "Give choice : " ch
	case $ch in
		'1')	echo "AAA"
			;;
		'2')	echo "BBB"
			;;
		'3')	echo "CCC"
			;;
		'4')	exit
			;;
		*)	echo "XXX"
			;;
	esac
done
