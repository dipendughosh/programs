//2*2 and 1*2 matrix find their product.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{	clrscr();
	int a[2][2],b[1][2];
	cout<<"Enter the elements of a 2*2 matrix : ";
	for(i=0;i<2;i++) for(j=0;j<2;j++) cin>>a[i][j];
	cout<<"\n\nEnter the elements of a 1*2 matrix : ";
	for(i=0;i<1;i++) for(j=0;j<2;j++) cin>>b[i][j];
