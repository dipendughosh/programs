# include <stdio.h>
# include <conio.h>
# include <math.h>
void main()
{
int a[3][3];
int i,j,s=0;
float n;
printf("enter the values");
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
scanf("%d",&a[i][j]);
}
}
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
printf("%d",a[i][j]);
}
printf("\n");
}
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
s=s+pow(a[i][j],2);
}
}
n=sqrt(s);
printf("the norm of the matrix is %f",n);
getch();
}
