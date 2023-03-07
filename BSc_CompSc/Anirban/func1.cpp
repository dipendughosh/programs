# include <stdio.h>
# include <conio.h>
void main()
{
int n=0;
void prime(int);
printf("enter number");
scanf("%d",&n);
getch();
}
void prime(int n)
{
int i,j;
for(i=2;i<=n/2;i++)
{
for(j=2;j<=i/2;j++)
{
if((i%j)==0)
break;
}
if(j>(i/2)&&(n%i)==0)
printf("%d ",i);
}
}
