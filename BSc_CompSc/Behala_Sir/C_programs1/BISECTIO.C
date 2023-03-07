#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<math.h>
float f(float x)
{
 return(x*x-9*x+2);
}
void main()
{
  float a,b,x,y;
  int flag=0;
  clrscr();
  printf("\n\n\t\tEnter lower limit:");
  scanf("%f",&a);
  printf("\n\n\t\tEnter upper limit:");
  scanf("%f",&b);
  if(f(b)>0&&f(a)<0)
  {
   y=b;
   b=a;
   a=y;
  }
  else if(f(a)*f(b)>0)
  {
   printf("\n\n\t\tWRONG DATA ENTRY");
   getch();
   exit(0);
  }
  y=a;
  do
  {
   flag=0;
   x=(a+b)/2;
   if(fabs(x-y)>.0005)
   {
    y=x;
    flag=1;
    if(f(x)>0)
    a=x;
    else
    b=x;
   }
   }while(flag);
  printf("\n\n\t\tThe root is: x=%f",x);
  getch();
}
