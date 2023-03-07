x=`echo "1+5+"|bc 2>/dev/null`
y=`printf "%d\n" $x`
if [ $y -eq 0 ]
then
	echo error
else
	echo $x
fi
