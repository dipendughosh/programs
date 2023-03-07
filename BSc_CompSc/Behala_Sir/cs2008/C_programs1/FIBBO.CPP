#include<stdio.h>
#include<conio.h>
void main()
{
int n,r,s,x,i,y;
clrscr();
n=1;r=0;
printf("enter num of terms = ");
scanf("%d",&x);
printf("%d %d ",r,n);
for(i=1;i<=x-2;i++)
{
s=n;
n=r+s;
r=s;
printf("%d ",n);
}
getch();
}
