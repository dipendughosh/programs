# include <stdio.h>
# include <conio.h>
void main()
{
int r=0;
float area(int);
printf("enter radius");
scanf("%d",&r);
printf("area is %f",area(r));
getch();
}
float area(int x)
{
float y=0.0,pie=3.14;
y=pie*(x*x);
return(y);
}