# include <stdio.h>
# include <conio.h>
void main()
{
float log(float),x=0.0;
float l;
printf("\n enter the value of x");
scanf("%f",&x);
l=log(x);
printf("the logarithm of the number is %f",l);
getch();
}
float log(float y)
{
int n=0,i,j;
float s=0.0,m=1.0;
printf("enter limit");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=i;j++)
{
m=m*((y-1)/y);
}
if(i==1)
s=s+m;
else
s=s+(m/2);
m=1.0;
}
return(s);
}
