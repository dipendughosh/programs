																 //*PROGRAM-11*
//*LEAP YEAR*
#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
	int y;
	cout<<"ENTER A YEAR ";
	cin>>y;
	if( y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
	 cout<<"IT IS A LEAP YEAR";
	else
	 cout<<"IT IS NOT A LEAP YEAR";
	getche();
}

