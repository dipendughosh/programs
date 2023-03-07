# include <stdio.h>
# include <conio.h>
void main()
{
int l=0;
int b=0,area(int,int),a;
printf("enter lenth and breadth");
scanf("%d%d",&l,&b);
a=area(l,b);
printf("area is %d",a);
getch();
}
area(int x,int y)
{
int c=0;
c=x*y;
return(c);
}
