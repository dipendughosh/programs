read -p "Enter n :- " n
i=1
while [ $i -le $n ]
do
	echo $i
	i=`expr $i + 1`
done
read -p "Enter n :- " n
i=1
while [ $i -le $n ]
do
	echo $i
	((i=i + 1))
done
read -p "Enter n :- " n
i=1
while [ $i -le $n ]
do
	echo $i
	((i++))
done
