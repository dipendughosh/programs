//sum of the diagonal elements of a 4x4 matrix.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
int i,j;
void main()
{	clrscr();
	cout<<"Enter the elements of a 4x4 matrix : ";
	int a[4][4],sum=0,x=3;
	for(i=0;i<4;i++) for(j=0;j<4;j++) cin>>a[i][j];
	for(i=0;i<4;i++) sum+=a[i][i];
	for(i=0;i<4;i++) sum+=a[x--][i];
	clrscr();
	for(i=0;i<4;i++)
	{	for(j=0;j<4;j++) cout<<"\t"<<a[i][j];
		cout<<endl;
	}
	cout<<"\n\tSUM : "<<sum;
	getch();
}
