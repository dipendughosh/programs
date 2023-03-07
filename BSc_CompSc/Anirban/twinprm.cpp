# include <stdio.h>
# include <conio.h>
void main()
{
int isprime(int),m=0,n=0,p,q,i;
printf("enter lower limit");
scanf("%d",&m);
printf("\n enter upper limit");
scanf("%d",&n);
for(i=m;i<=n;i++)
{
if(i>(n-2))
break;
p=isprime(i);
if(p)
{
q=isprime(i+2);
if(q)
printf("\n %d %d ",p,q);
}
}
getch();
}
isprime(int x)
{
int i;
for(i=2;i<=x/2;i++)
{
if((x%i)==0)
break;
}
if(i>(x/2))
return(x);
else
return(0);
}