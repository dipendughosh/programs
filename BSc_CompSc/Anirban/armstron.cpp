# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,i,s,x,p=0,m=0;
printf("enter upper limit");
scanf("%d",&n);
printf("\n enter lower limit");
scanf("%d",&m);
for(i=m;i<=n;i++)
{
x=i;
while(x>0)
{
s=(x%10);
p=p+(s*s*s);
x=(x/10);
}
if(p==i)
printf("%d ",i);
}
getch();
}