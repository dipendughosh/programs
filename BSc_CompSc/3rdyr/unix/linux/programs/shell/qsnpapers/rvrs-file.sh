if [ $# -ne 2 ]
then
	echo "ERROR:-"
	read -p "Enter source filename:- " src
	read -p "Enter destinatione filename:- " des
else
	src=$1
	des=$2
fi
i=1
while read t
do
	x=`tail -n $i $src|head -n 1`
	echo $x|cat>>$des
	i=`expr $i + 1`
done<$src
cat $src
cat $des