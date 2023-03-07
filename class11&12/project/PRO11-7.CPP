//program to convert binary numbers to decimal
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	long n,i,a,w,s,q;
	w=0;s=0;
	cout<<"Enter a binary number :";
	cin>>n;
	q=n;
	while(n>0)
	{	i=n%10;
		a=pow(2,w)*i;
		s=s+a;
		w++;
		n=n/10;
	}
	cout<<"\nThe decimal number is "<<s;
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}