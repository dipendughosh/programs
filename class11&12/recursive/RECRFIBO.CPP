//recursure fibonacci
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	double x=0,s=0,y=1,n;
	int fibo(int,int,int);
	cout<<"Enter limit :";
	cin>>n;
	s=x+y;
	cout<<x<<" "<<y<<" "<<s<<" ";
	x=y;y=s;
	fibo(x,y,n);
	cout<<"\nPRESS ANY KEY TO CONTINUE ............"<<(char)7;
	getche();
}
int fibo(int a,int b,int c)
{	int s=0;
	if(c==3)
		return(0);
	else
	{	s=a+b;
		cout<<s<<" ";
		a=b;b=s;
		fibo(a,b,(c-1));
	}
	return(0);
}