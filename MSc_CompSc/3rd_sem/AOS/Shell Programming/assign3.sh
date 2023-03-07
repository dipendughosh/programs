# -------------ASSIGNMENT 3-----------

echo "Enter filename: "
read fname

awk -F "|" '{print NF -1}' $fname > file

lc=`wc -l $fname | cut -d " " -f1`

i=1
echo "The file contents are:"
cat $fname

echo "Required line numbers are:"
while [ $i -le $lc ]
do
    c=`sed -n -e "$i p" file`
    if [ $c -lt 4 ]
    then
	echo $i
    fi
    i=`expr $i + 1`
done
echo "END"