read -p "Enter 1st hex number:- " n1
read -p "Enter 2nd hex number:- " n2
n3=`echo "($n1+$n2)"|bc`
printf "%X\n" $n3
