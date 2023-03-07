# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,i,j,k,f1=0,f2=1,f3;
char ch='A';
printf("enter the number of rows");
scanf("%d",&n);
if(n>7)
printf("ascii values will exceed that of big case and small case will appear\n");
printf("the output is as follows\n");
for(i=1;i<=n;i++)
{
for(k=1;k<=n-i;k++)
{
printf(" ");
}
for(j=1;j<=i;j++)
{
if(j==1)
{
printf("%c ",ch);
}
else
{
f3=f1+f2;
ch=ch+f2;
printf("%c ",ch);
f1=f2;
f2=f3;
}
}
printf("\n");
f3=0;
f1=0;
f2=1;
ch='A';
}
getch();
}