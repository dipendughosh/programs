# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,i,j,m=0;
printf("\n enter upper limit");
scanf("%d",&n);
printf("\n enter lower limit");
scanf("%d",&m);
for(i=m;i<=n;i++)
{
for(j=2;j<=(i/2);j++)
{
if((i%j)==0)
break;
}
if(j>(i/2))
printf("\n %d",i);
}
getch();
}
