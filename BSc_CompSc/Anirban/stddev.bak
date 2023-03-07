# include <stdio.h>
# include <conio.h>
# include <math.h>
void main()
{
int a[20];
int n,i,s=0,s1=0;
float sd,x1;
printf("number of values to be entered");
scanf("%d",&n);
for(i=0;i<=n-1;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<=n-1;i++)
{
s=s+a[i];
}
x1=(s/n);
for(i=0;i<=n-1;i++)
{
s1=s1+pow((a[i]-x1),2);
}
sd=sqrt(s1/n);
printf("standard deviation is %f",sd);
getch();
}
