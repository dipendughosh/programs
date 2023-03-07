#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{	clrscr();
	int n1,n2,prod=1,a,lar;
	cout<<"Enter two numbers : ";  cin>>n1>>n2;
	if(n1>n2) lar=n1;
	else lar=n2;
	for(a=2;a<=lar;a++)
	{   if(n1%a==0 || n2%a==0)
		{	while(n1%a==0 || n2%a==0)
			{	if(n1%a==0) n1/=a;if(n2%a==0) n2/=a;
				prod*=a;
			};
		}
	}
	cout<<"\n"<<prod;
	getch();
}