#include<stdio.h>
#include<conio.h>
void main()
{
int a[100],n,s,r,x,k,i;
printf("enter the range = ");
scanf("%d",&x);
k=1;n=1;r=0;
for(i=1;i<=x;i++)
{
s=n;
a[k]=n=s+r;
r=s;
k++;
i=n-1;
}
for(i=1;i<=x;i++)
{
for(s=0,r=1;r<k;r++)
{
if(i==a[r])
s++;
}
if(s==0)
printf("%d ",i);
}
getch();
}
