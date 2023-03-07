# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,i,j;
long f;
float x=0.0,s1=0.0,s2=0.0,s=0.0;
printf("enter the value of x");
scanf("%f",&x);
printf("\n enter the limit");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
f=1;
if((i%2)==0)
{
for(j=1;j<=i;j++)
{
f=f*j;
}
s1=s1+(x/f);
}
else
{
for(j=1;j<=i;j++)
{
f=f*j;
}
s2=s2+(x/f);
}
}
s=s2-s1;
printf("the sum is %f",s);
getch();
}