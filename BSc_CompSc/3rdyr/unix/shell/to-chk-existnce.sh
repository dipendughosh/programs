echo "For a list of items in the present directory"
for i in `ls`
do
	if [ "$i" != "$0" ]
	then
		if [ -f "$i" ]
		then
			str="$i is a file that is:"
			if [ -r "$i" ]
			then
				str="$str Readable"
			fi
			if [ -w "$i" ]
			then	
				str="$str Writeable"
			fi
			if [ -x "$i" ]
			then
				str="$str Executible"
			fi
			if [ -s "$i" ]
			then
				s=`ls -l $i|cut -d " " -f 5`
				str="$str size is $s"
			else
				str="$str size is 0"
			fi	
			s=`ls -l $i|cut -d " " -f 6`
			str="$str created on $s"
			s=`ls -l $i|cut -d " " -f 7`
			str="$str at $s"
		elif [ -d "$i" ]
		then
			str="$i is a Directory"
		else
			str="$i Does not exists"
		fi
		echo -e "$str"
	fi
done
