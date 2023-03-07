#include<stdio.h>
#include<conio.h>
void main()
{
int x,y,i,j,a,b,c,s;
printf("upper = ");
scanf("%d",&y);
printf("lower = ");
scanf("%d",&x);
for(i=x;i<=y;i++)
{
s=0;
a=i;
while(a!=0)
{
b=a%10;
a=a/10;
for(c=1,j=1;j<=b;j++)
{
c*=j;
}
s+=c;
}
if(s==i)
printf("%d  ",i);
}
getch();
}
