#include<conio.h>
#include<iostream.h>

void main()
{   clrscr();
	int reverse(int);
	int a,b,prod1=1,prod2=1;
	cout<<"Enter two numbers ==>\n ";
	cin>>a>>b;
	prod1=a*b;cout<<"prod1 : "<<prod1;
	prod2=(reverse(a)*reverse(b));    cout<<"\tprod2 : "<<prod2;
	if(prod1==prod2) cout<<"\n\nYes,the relation holds good .";
	else cout<<"\n\nNo,the relation does not hold good .";
	getch();
}


int reverse(int p)
{   int rem,sumrem=0;
	rem=p%10;
	sumrem+=(rem*10);
	p=(p-rem)/10;
	sumrem+=p;
	return sumrem;
}