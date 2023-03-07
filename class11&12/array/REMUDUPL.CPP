#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{	clrscr();
	int a[10],dup,i,j,k;
	for(i=0;i<10;i++)
		cin>>a[i];
	cout<<"Enter no to check";
	cin>>dup;
	k=10;
	for(i=0;i<k;i++)
	{	 if(a[i]==dup)
		{       k-=1;
			for(j=i;j<k;j++)
				a[j]=a[j+1];
		}

	}
	for(i=0;i<k;i++)
		cout<<a[i]<<"\t";
	getche();
}