# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,i;
int num=0,b=0,c=0,a=0;
printf("enter limit");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("enter number");
scanf("%d",&num);
if (num>0)
a=a+1;
if (num<0)
b=b+1;
if(num==0)
c=c+1;
}
printf("the number of +ve no.s is %d\n -ve is %d\n zero is %d",a,b,c);
getch();
}