# include <stdio.h>
# include <conio.h>
void main()
{
int n=0;
void fibonacci(int);
printf("enter the limit");
scanf("%d",&n);
fibonacci(n);
getch();
}
void fibonacci(int x)
{
int prime(int),f1=1,f2=1,f3,f;
while(x>2)
{
f3=f1+f2;
f=prime(f3);
if(f)
printf("%d ",f);
f1=f2;
f2=f3;
x=x-1;
}
}
prime(int y)
{
int i;
for(i=2;i<=y/2;i++)
{
if((y%i)==0)
break;
}
if(i>(y/2))
return(y);
else
return(0);
}