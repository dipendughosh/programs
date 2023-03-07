#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float);
float ff(float);
void main(void)
{
 float h,x,xn1,xn2,err;
 do
  {
   clrscr();
   printf("\n\nEnter a near about value: ");
   scanf("%f",&x);
   if((fabs(f(x)*ff(x)))<((ff(x))*(ff(x))))
    break;
   else
    {
     printf("\n\nWrong value entered!!!try again...");
     getch();
    }
  }while(1);
 printf("\n\nEnter the error: ");
 scanf("%f",&err);
 xn2=x;
 xn1=xn2;
 h=((f(xn1))/(ff(xn1)));
 xn2=xn1-h;
 while((fabs(xn1-xn2))>err)
  {
   xn1=xn2;
   h=((f(xn1))/(ff(xn1)));
   xn2=xn1-h;
  }
 printf("\n\nThe root is: %f",xn1);
 printf("\n\n\n\nThe 2nd root is: %f",xn2);
 getch();
}
float f(float x)
{
 return(pow(x,3)-3*x*x+2*x-5);
}

float ff(float x)
{
 return(3*pow(x,2)-6*x+2);
}

