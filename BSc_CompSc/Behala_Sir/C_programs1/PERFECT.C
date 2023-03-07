#include<stdio.h>
#include<conio.h>
void main()
{
int x,i,j,y,k;
//printf("lower = ");
printf("enter any num = ");
scanf("%d",&x);
//printf("upper = ");
//scanf("%d",&y);
//for(i=x;i<=y;i++)
//{
//for(k=1,j=0;k<i;k++)
//{
//if(i%k==0)
//j=j+k;
//}
//if(j==i)
//printf("%d ",i);
//}
for(i=1,j=0;i<x;i++)
{
if(x%i==0)
j=j+i;
}
if(j==x)
printf("%d is a perfect number",x);
else
printf("%d is not a perfect number",x);
getch();
}


