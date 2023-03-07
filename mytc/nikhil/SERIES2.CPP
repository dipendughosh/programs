//x-(1/3!*x^3)+(1/5!*x^5)......n
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{	clrscr();
	float pcalc(int,int);
	float fact(int);
	int i=1,n,x,m=1,inc;
	float val,sum=0.0,y,factorial,power;
	cout<<"Enter the constant value (X) : ";  cin>>x;
	cout<<"\nEnter the number of times (N) : ";  cin>>n;
	for(;i<=n;i+=2)
	{   cout<<"i:"<<i<<"\t";
		factorial=fact(i);
		power=pcalc(i,x);  y=1/factorial; cout<<"y:"<<y<<"  ";getch();

		val=((1/factorial)*power*m);  cout<<"val:"<<val<<endl;    getch();
		sum+=val;
		m*=-1;
	}
	cout<<"\n\nSUM : "<<sum;
	getch();
}


float pcalc(int p,int q)
{   int a=0,po=1;
	for(;a<p;a++) po*=q;
	return po;
}

float fact(int p)
{
int f=1;
while(p) f*=p--; cout<<"f:"<<f<<"\t";
return f;
}