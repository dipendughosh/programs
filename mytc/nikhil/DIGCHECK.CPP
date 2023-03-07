#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{	clrscr();
	unsigned int n,div;
	int rem,a,flag=0;
	cout<<"Enter a multi-digit number : "; cin>>n;
	cout<<"Number to check : "; cin>>a;
	div=n;
	while(div)
	{   rem=div%10;
		div/=10;
		if(rem==a)
		{	flag=1;
			break;
		}
	};
	if(flag==1) cout<<"The number is present.";
	else cout<<"The number is not present.";
	getch();
}