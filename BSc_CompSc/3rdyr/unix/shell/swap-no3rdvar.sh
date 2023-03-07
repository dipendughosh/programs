read -p "Enter 1st hex number:- " a
read -p "Enter 2nd hex number:- " b
echo -e "Before swaping the values are:-\na = $a\nb = $b"
a=`expr $a + $b`
b=`expr $a - $b`
a=`expr $a - $b`
echo -e "After swaping the values are:-\na = $a\nb = $b"

