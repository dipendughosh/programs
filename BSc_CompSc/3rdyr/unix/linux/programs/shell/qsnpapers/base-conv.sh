read -p "Enter input base :- " ib
read -p "Enter output base :- " ob
read -p "Enter number in the input base :- " num
num=`echo $num|tr 'a-f' 'A-F'`
x=`echo -e "obase=$ob\nibase=$ib\n$num"|bc`
echo $x

