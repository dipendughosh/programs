//calculating sum of a factorial series
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	float n,fact=1,sum=0;
	cout<<"Enetr the range of the series :";
	cin>>n;
	for(int i=1;i<=n;i++)
	{	for(int j=1;j<=i;j++)
		{	fact=fact*j;
		}
		sum=sum+(1/fact);
		fact=1;
	}
	cout<<"\nThe sum of the series is "<<sum;
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}