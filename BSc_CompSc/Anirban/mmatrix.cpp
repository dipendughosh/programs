# include <stdio.h>
# include <conio.h>
int main()
{
int a[3][3],b[3][3],c[3][3];
int i,j,k,s=0;
printf("enter the values of a");
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
printf("%d ",a[i][j]);
}
printf("\n");
}
printf("enter the values of b");
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
scanf("%d",&b[i][j]);
}
}
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
printf("%d ",b[i][j]);
}
printf("\n");
}
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
for(k=0;k<=2;k++)
{
s=s+(a[i][k]*b[k][j]);
}
c[i][j]=s;
s=0;
}
}
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
printf("%d ",c[i][j]);
}
printf("\n");
}
getch();
return(0);
}