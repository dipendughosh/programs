//HCF.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{	clrscr();
	int n1,n2,lar,hcf,f[20],i=0;
	int r,rept=0;
	cout<<"Enter two nos. to find HCF : \n";
	cin>>n1>>n2;
	if(n1>n2) lar=n1;
	else lar=n2;
	for(int a=1;a<=lar;a++)
	{	if(n1%a==0 && n2%a==0) hcf=a;
		else continue;
	}
	cout<<"\nHCF : "<<hcf;
	getch();
}