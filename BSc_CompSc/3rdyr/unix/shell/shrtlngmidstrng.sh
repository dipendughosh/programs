read -p "Give string " s
l=`expr length "$s"`
if [ $l -gt 20 ]
then
	echo "Long String"
elif [ $l -gt 10 ]
then
	echo "Mid String"
else
	echo "Short String"
fi
