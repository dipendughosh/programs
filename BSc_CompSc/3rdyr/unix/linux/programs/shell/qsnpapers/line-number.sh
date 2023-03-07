if [ $# -lt 2 ]
then
	echo "ERROR:- Too few arguments:"
	exit
fi
grep -n $2 $1|cat>temp.txt
i=`wc -l temp.txt`
echo "The word $2 is present in $1 ${i[0]} times at the following lines :-"
cut -d ":" -f 1 temp.txt

