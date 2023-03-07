//*LEAP YEAR*
#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
	int y;
	cout<<"enter year";
	cin>>y;
	if( y % 4 == 0 && y % 100 != 0 || y % 400 == 0 )
		cout<<y<<" IS A LEAP YEAR ";
	else
		cout<<y<<" IS NOT A LEAP YEAR ";
  getche();
}