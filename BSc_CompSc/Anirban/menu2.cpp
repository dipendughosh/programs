# include <stdio.h>
# include <conio.h>
void main()
{
/*peterson series*/
int n=0,i,s,x,p,j,f;
printf("enter limit");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
x=i;
p=0;
while(x>0)
{
f=1;
s=x%10;
for(j=1;j<=s;j++)
{
f=f*j;
}
p=p+f;
x=x/10;
}
if(p==i)
{
printf("%d ",i);
}
}
getch();
}