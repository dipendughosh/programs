src="library.txt"

#ACCESNO/BOOKNAME/AUTHNAME/SUBJECT/PUBLICATION/NOCOPIES/YEARPUB

echo -e "\tMENU"
echo -e "1.Enter new books"
echo -e "2.Update subject of a book"
echo -e "3.List all books of some publication"
echo -e "4.Sort by Subject-Author Name-Publisher"
echo -e "5.Delete a book"
echo -e "6.Number of copies of a book"
echo -e "7.Sort by Publisher and number of books by the Publisher"
echo -e "8.Publisher with highest number of books"
echo -e "9.Exit"
read -p "Enter choice:- " ch

case $ch in
        '1')
	      echo "ACCESNO/BOOKNAME/AUTHNAME/SUBJECT/PUBLICATION/NOCOPIES/YEARPUB"|cat>>$src

	      while true
	      do
		  read -p "Enter Book Access Number:- " no 
		  read -p "Enter Book Name :- " name
		  read -p "Enter Author Name :- " aname
		  read -p "Enter Subject :- " sub
		  read -p "Enter Publisher :- " pub
		  read -p "Enter Number of Copies :- " nocop
		  read -p "Enter Year of Publication :- " ypub
		  echo "$no/$name/$aname/$sub/$pub/$nocop/$ypub"|cat>>$src
		  read -p "Do you want to enter more?(Y/y) " c
		  if [ $c != 'y' ]
		  then
			if [ $c != 'Y' ]
			then
			      break
			fi
		  fi
	      done
	;;
	'2')
	      read -p "Enter Book Access Number to update subject:- " acno
	      read -p "Enter Subject :- " ssub
	      
	      while read t
	      do
		  no=`echo "$t"|cut -d'/' -f'1'`
		  name=`echo "$t"|cut -d'/' -f'2'`
		  aname=`echo "$t"|cut -d'/' -f'3'`
		  sub=`echo "$t"|cut -d'/' -f'4'`
		  pub=`echo "$t"|cut -d'/' -f'5'`
		  nocop=`echo "$t"|cut -d'/' -f'6'`
		  ypub=`echo "$t"|cut -d'/' -f'7'`
		  
		  if [ $no == $acno ]
		  then
			echo "$no/$name/$aname/$ssub/$pub/$nocop/$ypub"|cat>>temp.txt
		  else
			echo "$no/$name/$aname/$sub/$pub/$nocop/$ypub"|cat>>temp.txt
		  fi
	     done<$src
	     mv temp.txt $src
	;;
	'3')
	     read -p "Enter Publication :- " publi
	     
	     while read t
	     do
		  no=`echo "$t"|cut -d'/' -f'1'`
		  name=`echo "$t"|cut -d'/' -f'2'`
		  aname=`echo "$t"|cut -d'/' -f'3'`
		  sub=`echo "$t"|cut -d'/' -f'4'`
		  pub=`echo "$t"|cut -d'/' -f'5'`
		  nocop=`echo "$t"|cut -d'/' -f'6'`
		  ypub=`echo "$t"|cut -d'/' -f'7'`
		  
		  if [ $pub == $publi ]
		  then
			echo "Book Name :- $name"
			echo "By :- $aname"
			echo "On :- $sub"
			echo "Number of Copies Available :- $nocop"
			echo "Published in the Year :- $ypub"
		  fi
	     done<$src
	;;
	'4')
	     sort -t"/" -k 4 -k 3 -k 5 $src -o temp1.txt	
	     echo -v"/" | cat temp1.txt
	     rm temp1.txt
	;;
	'5')
	     read -p "Enter Book Access Number to delete :- " acno
	     
	     while read t
	     do
		  no=`echo "$t"|cut -d'/' -f'1'`
		  name=`echo "$t"|cut -d'/' -f'2'`
		  aname=`echo "$t"|cut -d'/' -f'3'`
		  sub=`echo "$t"|cut -d'/' -f'4'`
		  pub=`echo "$t"|cut -d'/' -f'5'`
		  nocop=`echo "$t"|cut -d'/' -f'6'`
		  ypub=`echo "$t"|cut -d'/' -f'7'`
		  
		  if [ $no != $acno ]
		  then
			echo "$no/$name/$aname/$sub/$pub/$nocop/$ypub"|cat>>temp2.txt
		  fi
	     done<$src
	     mv temp2.txt $src
	;;
	'6')
	     read -p "Enter Book Name :- " bname
	     read -p "Enter Author Name :- " athname
	     
	     while read t
	     do
		  no=`echo "$t"|cut -d'/' -f'1'`
		  name=`echo "$t"|cut -d'/' -f'2'`
		  aname=`echo "$t"|cut -d'/' -f'3'`
		  sub=`echo "$t"|cut -d'/' -f'4'`
		  pub=`echo "$t"|cut -d'/' -f'5'`
		  nocop=`echo "$t"|cut -d'/' -f'6'`
		  ypub=`echo "$t"|cut -d'/' -f'7'`
		  
		  if [ $name == $bname -a $aname == $athname ]
		  then
			echo "Number of Copies Available :- $nocop"
		  fi
	     done<$src
	;;
	'7')
	     sort -t"/" -k 5 $src -o temp1.txt	
	     echo -v"/" | cat temp1.txt
	     rm temp1.txt
	      
	     sort -t"/" -k 5 $src | cut -d"/" -f 5 | uniq -c
	;;
	'8')
	     sort -t"/" -k 5 $src | cut -d"/" -f 5 | uniq -c | cat>>temp.txt
	     sort -k 1 temp.txt | tail -n 1 | cat>>t.txt
	     cat t.txt
	     rm temp.txt
	     rm t.txt
	;;
	'9')
    exit
	;;
        *)
	;;
esac