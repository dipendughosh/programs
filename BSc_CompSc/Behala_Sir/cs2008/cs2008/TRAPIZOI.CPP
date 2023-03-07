// TO FIND THE ROOT OF A EQ BY TRAPIZIODAL_RULE METHOD
//FOR INTREGRATION(3X^2+2X+3) (Using up&low limit)

#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x)
 {
   return(3*x*x+2*x+3.0);
 }
 void main()
 {  float x[50],y[50],h,a,b,sum1=0.0;
    int i,n;
    clrscr();
    printf("\n\n ENTER THE LOWER & UPPER LIMIT: \n");
    scanf("%f%f",&a,&b);
    printf("\n\n ENTER NO. OF SUBINTERVALS: \n ");
    scanf("%d",&n);
    h=(b-a)/n;
    x[0]=a;
    x[n]=b;
    y[0]=f(x[0]);
    y[n]=f(x[n]);
    for(i=1;i<n;i++)
     { x[i]=x[0]+i*h;
       y[i]=f(x[i]);
       sum1=sum1+y[i];
     }
    sum1=(h/2)*(y[0]+y[n]+2*sum1);
    printf("\n\n RESULT IS  %f",sum1);
    getch();
 }
