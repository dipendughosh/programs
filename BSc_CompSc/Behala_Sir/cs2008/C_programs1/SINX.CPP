#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int i,j,a,b,n;
float x,s;
printf("enter the num of terms = ");
scanf("%d",&n);
printf("put the value of x in degree = ");
scanf("%f",&x);
x=(3.14*x)/180;
s=0;
for(a=1,b=3,j=2,i=1;i<n;i++)
{
a=a*j*b;
s=x+((pow(-1,i)*pow(x,b))/a);
j=j+2;
b=b+2;
}
printf("sinx = %f",s);
getch();
}

