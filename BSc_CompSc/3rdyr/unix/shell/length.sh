a=xyz
echo "a = " $a
b=$a
echo "b = " $b
b="abc "$a" pqr"
echo "b = " $b
l=`expr length "Hello World"`
echo -e "Length of \"Hello World\" = " $l
echo "Enter a string with no space : - "
read a
l=`expr length $a`
echo "Length of $a = " $l
read -p "Enter a string : - " a
l=`expr length "$a"`
echo "Length of $a = " $l
