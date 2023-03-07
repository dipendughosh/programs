read -p "Extension to replace :- " s
read -p "Extension to replace with :- " d
a=`ls *.$s`
echo $a
for i in $a
do
	b=`echo $i|cut -d'.' -f1`
	mv $b.$s $b.$d
done


