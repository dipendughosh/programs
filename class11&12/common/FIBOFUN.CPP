#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
void main()
{	clrscr();
	int a[100],k=1,i,s=0;
	a[0]=0;
	a[1]=1;
	for(i=2;i<100;i++)
	{	a[i]=a[i-2]+a[i-1];
		k++;
		if(a[i]>100)
			break;
	}
	cout<<"\nK="<<k;
	cout<<"\n\n\n";
	for(i=0;i<=(k-1);i++)
		cout<<a[i]<<"\t";
	cout<<"\n\n\n";
	for(i=(k-1);i>=0;i--)
		cout<<a[i]<<"\t";
	cout<<"\n\n\n";
	for(i=0;i<=(k-1);i+=3)
	{       cout<<a[i]<<"\t";
		s=s+a[i];
	}
	cout<<"\n\n\n";
	cout<<"\nSUM OF 4th NUMBERS = "<<s;
	getche();
}