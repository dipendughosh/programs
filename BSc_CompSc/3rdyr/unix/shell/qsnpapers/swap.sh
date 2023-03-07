read -p "Enter 1st number:- " n
read -p "Enter 2nd number:- " m
n=`expr $n + $m`
m=`expr $n - $m`
n=`expr $n - $m`
echo -e "$n \t $m"
