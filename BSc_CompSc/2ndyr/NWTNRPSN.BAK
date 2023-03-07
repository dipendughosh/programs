//Newton Rapson
#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x)
{	return(pow(x,3)-3*x+1.06);
}

float fd(float x)
{	return(3*pow(x,2)-3);
}

float fdd(float x)
{	return(6*x);
}

void main()
{	float a,er,x,h;
	int i=0;
	clrscr();
	do
	{	clrscr();
		printf("Enter initial value :- ");
		scanf("%f",&a);
		if(fabs(f(a)*fdd(a))<fabs(fd(a)*fd(a)))
			break;
		else
		{	printf("Re-enter\n");
			getch();
		}
	}while(1);
	printf("\nEnter the error :- ");
	scanf("%f",&er);
	x=a-(f(a)/fd(a));
	printf("\nn\ta\t\tf(x)\t\tf'(x)\t\th\t\tx");
	while(fabs(x-a)>er)
	{	a=x;
		h=(f(a)/fd(a));
		x=a-h;
		printf("\n%d\t%f\t%f\t%f\t%f\t%f",i++,a,f(x),fd(x),h,x);
	}
	printf("\nx=%f",x);
	getch();
}

