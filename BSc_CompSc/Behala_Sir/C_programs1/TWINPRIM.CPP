#include<stdio.h>
#include<conio.h>
void main()
{
int a[100],x,i,j,k,c,b;
printf("enter range = ");
scanf("%d",&x);
for(k=0,i=1;i<=x;i++)
{
for(c=0,j=1;j<=i;j++)
{
if(i%j==0)
c++;
}
if(c==2 || c==1)
{
a[k]=i;
k=k+1;
}
}
for(i=0;i<k;i++)
{
if(a[i+1]-a[i]==2)
printf("%d,%d   ",a[i],a[i+1]);
}
getch();
}
