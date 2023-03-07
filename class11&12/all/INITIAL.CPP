#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{	clrscr();
	int p,x,i,j,k;
	char a[500];
	gets(a);
	p=strlen(a);
	x=p-1;
	for (i=p-1;a[i]!=' ';i--)
		x--;
	cout<<a[0]<<".";
	for (j=1;j<=x-1;j++)
		if (a[j]==' ')
			cout<<a[j+1]<<".";
	for (k=x+1;a[k]!='\0';k++)
		cout<<a[k];
	//cout<<".";
	getche();
}