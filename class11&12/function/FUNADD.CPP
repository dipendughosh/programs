#include<iostream.h>
#include<conio.h>
void main()
{	int x,y;
	int sum(int,int);
	int getnum();
	clrscr();
	cout<<"ENTER THE VALUES OF X AND Y ";
	gotoxy(25,10);
	x=getnum();
	gotoxy(25,12);
	y=getnum();
	gotoxy(25,20);
	cout<<"\nSUM OF NUMBERS "<<sum(x,y);
	getche();
}
int sum(int a,int b)
{	int s;
	s=a+b;
	return s;
}
int getnum()
{	int number;
	cout<<"\nENTER THE NUMBER ";
	cin>>number;
	cout<<endl;
	return number;
}