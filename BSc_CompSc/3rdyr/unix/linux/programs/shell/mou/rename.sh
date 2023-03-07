a=`ls *.txt`
echo $a
for i in $a
do
	b=`echo $a|cut -d'.' -f1`
	mv $b.txt $b.cpp
done


mv: cannot stat `test10.txt': No such file or directory

