#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{
clrscr();
int j,z=0;
int a[8]={0,1,1,3,5,6,8,8};
for(int i=1;i<8-z;i++)
if(a[i-1]==a[i])  {	;z++;for(j=i-1;j<7;j++)  a[j]=a[j+1];}
for (int x=0;x<8-z;x++)  cout<<a[x]<<"  ";
getch();
}