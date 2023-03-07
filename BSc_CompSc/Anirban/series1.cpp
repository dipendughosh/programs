# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,s=0,s1=0,s2=0,i;
printf("enter limit");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
if((i%2)==0)
s1=s1+(i*i*i*i);
else
s2=s2+(i*i*i);
}
s=s2-s1;
printf("the sum of the series is %d",s);
getch();
}