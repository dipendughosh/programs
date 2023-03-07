read -p "Enter a arithemtic expression with '+,-,*,/,(,)' :- " s
x=`echo $s|bc 2>/dev/null`
echo $x
