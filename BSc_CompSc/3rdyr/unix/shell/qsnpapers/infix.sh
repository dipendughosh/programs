read -p "Enter a infix expression with parentahesis:-" n
x=`echo "$n"|bc`
echo "Result of $n = $x"
