# include <stdio.h>
# include <conio.h>
# include <math.h>
void main()
{
int n=0,i,j,x;
float sum=0.0;
long fact(int);
printf("enter limit");
scanf("%d",&n);
printf("\n enter the value of x");
scanf("%d",&x);
for(i=1;i<=n;i++)
{
j=(2*i)-1;
sum=sum-(pow(-1,i)*pow(x,j))/fact(j);
}
printf("the sum is %f",sum);
getch();
}
long fact(int n)
{
long f=1;
int k;
for(k=1;k<=n;k++)
{
f=f*k;
}
return(f);
}
/*sine series*/