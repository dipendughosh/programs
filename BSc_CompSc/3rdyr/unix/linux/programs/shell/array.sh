a[0]=10
a[1]=20
a[2]=30
echo "Printing whole array one by one"
for i in `seq 0 2`
do
	echo ${a[$i]}
done


a[0]=40
a[1]=50
a[2]=60
echo "Printing whole array at a time"
echo ${a[*]}


a[0]=70
a[1]=80
a[2]=90
a[3]=100
a[4]=110
a[6]=130
echo "Printing number of elements of array"
echo ${#a[*]}


echo "Printing dynamic array"
a[0]=10
a[1]=20
a[2]=30
a[3]=40
a[4]=50
a[5]=70
echo "Printing number of elements of array"
echo ${#a[*]}
n=${#a[*]}
t=`expr $n - 1`
for i in `seq 0 $t`
do
	echo "a[$i] = " ${a[$i]}
done

echo "Entering array from user and printing it"
read -p "Give number of elements :- " n
for i in `seq 0 $((n-1))`
do
	read -p "Give data at a[$i] = " a[$i]
done

