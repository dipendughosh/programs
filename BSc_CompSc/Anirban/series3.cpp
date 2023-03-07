# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,i,j,s;
float x=0.0;
printf("enter the limit");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
s=0;
for(j=1;j<=i;j++)
{
s=s+j;
}
x=x+(1.0/s);
}
printf("sum is %f",x);
getch();
}