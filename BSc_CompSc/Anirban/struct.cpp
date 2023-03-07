# include <stdio.h>
# include <conio.h>
# include <math.h>
void main()
{
int n=0,s=0,c=0,x=0,i,j;
printf("enter limit");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
s=pow(11,c);
c=c+1;
for(j=1;j<=(n-i);j++)
{
printf(" ");
}
while(s>0)
{
x=s%10;
printf("%d ",x);
s=s/10;
}
printf("\n");
}
getch();
/*output is obtained but garbage value for higher limits*/
}