# -------------ASSIGNMENT 4-----------

who | cut -d " " -f1 >file1
term=`tty`

echo "User name        ID"
exec <file1

i=1
while read line
do
    echo "$line  "
    ids=`id -u $line`
    echo $ids
    i=`expr $i + 1`
done
exec <$term

ps -el | awk -F " " '{print $2}' > file2
ps -el | awk -F " " '{print $4}' > file22
ps -el | awk -F " " '{print $14}'  > file3

lc=`wc -l file2 | cut -d " " -f1`

i=2
echo "-------------------------------------------"
echo "Sleeping Prosesses"
echo "-------------------------------------------"
while [ $i -le $lc ]
do
    str1=`sed -n -e "$i p" file2`
    
    if [ $str1 = "S" ]
    then
	d=`sed -n -e "$i p" file22`
	d1=`sed -n -e "$i p" file3`
	echo "$d       "
	echo $d1
    fi
    i=`expr $i + 1`
done

i=2
echo "-------------------------------------------"
echo "Running Processes"
echo "-------------------------------------------"
while [ $i -le $lc ]
do
    str1=`sed -n -e "$i p" file2`

    if [ $str1 = "R" ]
    then
	d=`sed -n -e "$i p" file22`
	d1=`sed -n -e "$i p" file3`
	echo "$d       "
	echo $d1
    fi
    i=`expr $i + 1`
done

echo "END"