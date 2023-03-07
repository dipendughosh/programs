# include <stdio.h>
# include <conio.h>
void main()
{
int isprime(int),n=0,p,i;
printf("enter the number");
scanf("%d",&n);
for(i=n+1; ;i++)
{
p=isprime(i);
if(p)
break;
}
printf("the next prime number is %d",p);
getch();
}
isprime(int x)
{
int i;
for(i=2;i<=x/2;i++)
{
if ((x%i)==0)
break;
}
if(i>(x/2))
return(x);
else
return(0);
}