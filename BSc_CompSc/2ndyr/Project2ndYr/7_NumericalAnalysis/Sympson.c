//Sympson's 1/3 rule to solve an integral function
#include<stdio.h>
#include<conio.h>
#include<math.h>

//Given integral function
float f(float x)
{	return((4*x)-(3*(pow(x,2))));
}

void main()
{       float a,b,x[50],y[50],s1=0.0,s2=0.0,h;
	int n,i;
       //	clrscr();
	printf("Lower Limit-");
	scanf("%f",&a);
	printf("\nUpper Limit-");
	scanf("%f",&b);
	printf("\nEnter no. of subintervals-");
	scanf("%d",&n);
	//Sympson 1/3 Rule logic
	h=(b-a)/n;
	x[0]=a;
	x[n]=b;
	y[0]=f(x[0]);
	y[n]=f(x[n]);
	for(i=1;i<n;i+=2)
	{	x[i]=x[0]+(i*h);
		y[i]=f(x[i]);
		s1=s1+y[i];
	}
	for(i=2;i<n;i+=2)
	{	x[i]=x[0]+(i*h);
		y[i]=f(x[i]);
		s2=s2+y[i];
	}
	s1=(h/3)*(y[0]+y[n]+(4*s1)+(2*s2));
	printf("\nI=%f",s1);
	getch();
}


Output:-

Lower Limit-0                                                                
Upper Limit-1                                                                 
Enter no. of subintervals-10                                                  
I=1.000000
