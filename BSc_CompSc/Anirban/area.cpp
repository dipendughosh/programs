# include <stdio.h>
# include <conio.h>
void  main()
{
int l=0,b=0,a;
printf("enter lenth and breadth");
scanf("%d%d",&l,&b);
a=area(l,b);
printf("%d area is",a);
}
area(int l,int b)
{
int c=0;
c=l*b;
return(c);
}
getch();

