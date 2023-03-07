//input:ten nos.,no.to be eliminated and no.to be replaced.
//output:all the nos. remaining get shifted to right and the rest filled
//with the replacement digit.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{   clrscr();
	int a[10],two,three;
	cout<<"Enter ten numbers : \n";
	for(int i=0;i<10;i++) cin>>a[i];
	cout<<"\nEnter the number to be checked : "; cin>>two;
	cout<<"\nEnter the number to be replaced : "; cin>>three;
	for(int z=0;z<10;z++)
	{	if(a[z]==two)
		{	for(int i=z;i>0;i--)  a[i]=a[i-1];
			a[i]=three;
		}
	}
	cout<<"\n";
	for(i=0;i<10;i++) cout<<a[i]<<"  ";
	getch();
}