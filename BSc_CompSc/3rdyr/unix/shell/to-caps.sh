echo -e "\n1\nTo convert all lower case letters to upper case letters(On screen):-"
cat $1|tr '[a-z]' '[A-Z]'
more
echo -e "\n2\nTo convert all lower case letters to upper case letters(On screen):-"
tr '[a-z]' '[A-Z]'<$1
echo -e "\n3\nTo convert all lower case letters to upper case letters(To output file):-"
tr '[a-z]' '[A-Z]'<$1>xyz.c
cat xyz.c
echo -e "\n4\nTo convert all lower case letters to upper case letters(To output file and On screen):-"
tr '[a-z]' '[A-Z]'<$1|tee abc.c

echo -e "\n5\nTo convert all lower case letters to upper case letters(From user To output file and On screen):-"
read -p "Enter source file:-" n1
read -p "Enter target file:-" n2
tr '[a-z]' '[A-Z]'<$n1|tee $n2
