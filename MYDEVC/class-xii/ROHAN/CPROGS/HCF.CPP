//HCF.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{	clrscr();
	int n1,n2,lar,hcf;
	cout<<"Enter two nos. to find HCF : \n";
	cin>>n1>>n2;
	if(n1>n2) lar=n1;
	else lar=n2;
	for(int a=1;a<=lar;a++)
	{	if(n1%a==0 && n2%a==0) hcf=a;
		else continue;
	}
	cout<<"\nHCF : "<<hcf;
	cout<<"\nLCM : "<<(n1*n2)/hcf;
	getch();
}