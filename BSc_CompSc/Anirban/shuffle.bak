# include <stdio.h>
# include <conio.h>
# include <math.h>
void main()
{
int x[10],y[10],p[10];/*this program is giving an error*/
int i,s=0,j=0,k=0,e=0,f=0;
float r,r1;
printf("enter the values of x");
for(i=0;i<=9;i++)
{
scanf("%d",&x[i]);
}
printf("enter the values of y");
for(i=0;i<=9;i++)
{
scanf("%d",&y[i]);
}
for(i=0;i<=9;i++)
{
p[i]=x[i]*y[i];
}
for(i=0;i<=9;i++)
{
s=s+p[i];
}
for(i=0;i<=9;i++)
{
j=j+x[i];
k=k+y[i];
}
for(i=0;i<=9;i++)
{
e=e+pow(x[i],2);
f=f+pow(y[i],2);
}
e=e*10;
f=10*f;
r1=sqrt((e-pow(j,2))*(f-pow(k,2)));
r=(((j*k)-s)/r1);
printf("the correlation coefficient is %f",r);
getch();
}


