#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{   clrscr();
	unsigned int fact(int);
	void print(int);
	unsigned int f,div;
	int n,rem;
	cout<<"Enter a number : ";  cin>>n;
	f=fact(n);     cout<<"\n"<<f<<"\n";
	div=f;
	while(div)
	{	rem=div%10;
		if(rem!=0) {print(rem);break;}
		div/=10;
	};
	getch();
}


unsigned int fact(int p)
{	unsigned int f=1;
	while(p)
	{f*=p--;};
	return f;
}

void print(int p)
{	cout<<"\nThe first non-zero number is : "<<p;
}