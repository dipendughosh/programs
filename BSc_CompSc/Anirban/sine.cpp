# include <stdio.h>
# include <conio.h>
# include <math.h>
void main()
{
int n=0,x=0,i,j;
long fact=1;
float sum=0.0;
printf("enter value of n");
scanf("%d",&n);
printf("\n enter the value of x");
scanf("%d",&x);
for(i=1;i<=n;i++)
{
for(j=1;j<=(2*i)-1;j++)
{
fact=fact*j;
}
sum=sum-(pow(-1,i))*pow(x,(2*i)-1))/fact;
}
printf("the sum is %f",sum);
getch();
}