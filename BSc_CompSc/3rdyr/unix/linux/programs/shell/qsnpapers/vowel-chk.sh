read -p "Enter a word :- " str
l=`expr length $str`
f=0
for i in `seq $l`
do
	x=`expr substr $str $i 1`
	if [ $x == "a" ]
	then
		f=1
	elif [ $x == "e" ]
	then
		f=1
	elif [ $x == "i" ]
	then
		f=1
	elif [ $x == "o" ]
	then
		f=1
	elif [ $x == "u" ]
	then
		f=1
	fi
done
if [ $f -eq 0 ]
then
	echo "Vowel not present in the word $str"
else
	echo "Vowel present in the word $str"
fi

