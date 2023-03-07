# include <stdio.h>
# include <conio.h>
void main()
{
int sum(int),n=0,s;
printf("enter number");
scanf("%d",&n);
s=sum(n);
printf("the sum is %d",s);
getch();
}
sum(int x)
{
int r;
if((x/10)==0)
{
r=x%10;
return(r);
}
else
{
r=x%10;
return(r+sum(x/10));
}
}