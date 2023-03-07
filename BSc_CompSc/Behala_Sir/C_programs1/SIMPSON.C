// TO FIND THE INTREGRATION OF A EQ BY SIMPSON METHOD
//FOR  Intregration [e^(tan(x))]

#include<stdio.h>
#include<conio.h>
#include<math.h>

double f(double g)
 {
     return (exp(tan(g)));
 }

void main()
 {
 double a,b,x[50],y[50],h,sum1=0.0,sum2=0.0 ;
 int n,i;
 clrscr();
 printf("\n ENTER LOWER & UPPER LIMIT : \n   ");
 scanf("%lf %lf",&a,&b);
 printf("\n ENTER NO.OF SUBINTERVALS : \n   ");
 scanf("%d",&n);
 h=(b-a)/n;
 x[0]=a;
 x[n]=b;
 y[0]=f(x[0]);
 y[n]=f(x[n]);
 for(i=1;i<n;i+=2)
   { x[i]=x[0]+i*h;
     y[i]=f(x[i]);
     sum1=sum1+y[i];
   }
 for(i=2;i<n;i+=2)
  { x[i]=x[0]+i*h;
    y[i]=f(x[i]);
    sum2=sum2+y[i];
  }
  sum1=(h/3.0)*(y[0] + y[n] + 4*sum1 + 2*sum2);
  printf("\n\nResult is  %lf",sum1);
  getch();
 }