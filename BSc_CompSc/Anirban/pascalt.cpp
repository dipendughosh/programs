# include <stdio.h>
# include <conio.h>
void main()
{
int pt(int,int),h=0,i,j;
printf("enter the height");
scanf("%d",&h);
for(i=1;i<=h;i++)
{
for(j=1;j<=i;j++)
{
printf("%d ",pt(i,j));
}
printf("\n");
}
getch();
}
pt(int x,int y)
{
if((y==1)||(y==x))
return(1);
else
return(pt(x-1,y-1)+pt(x-1,y));
}
