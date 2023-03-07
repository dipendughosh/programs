//Newton Rapson Method to solve a given equation
#include<stdio.h>
#include<conio.h>
#include<math.h>

//Given function
float f(float x)
{	return(pow(x,3)-(8*x)-4);
}

//1st order derivative of the given function
float fd(float x)
{	return(3*pow(x,2)-8);
}

//2nd order derivative of the given function
float fdd(float x)
{	return(6*x);
}

void main()
{       //Declaring variables
	float a,er,x,h;
	int i=0;
	clrscr();
	do
	{	clrscr();
		printf("Enter initial value :- ");
		scanf("%f",&a);
		//Checking convergency of the entered value
		if(fabs(f(a)*fdd(a))<fabs(fd(a)*fd(a)))
			break;
		else
		{	printf("Re-enter\n");
			getch();
		}
	}while(1);
	//Newton Rapshon Method logic
	printf("\nEnter the error :- ");
	scanf("%f",&er);
	x=a-(f(a)/fd(a));
	printf("\nn\ta\t\tf(x)\t\tf'(x)\t\th\t\tx");
	printf("\n%d\t%f\t%f\t%f\t%f\t%f",i++,a,f(x),fd(x),h,x);
	while(fabs(x-a)>er)
	{	a=x;
		h=(f(a)/fd(a));
		x=a-h;
		printf("\n%d\t%f\t%f\t%f\t%f\t%f",i++,a,f(x),fd(x),h,x);
	}
	printf("\nx=%f",x);
	getch();
}






Output:-

Enter initial value :- 3                                             
                                                                              
Enter the error :- .0005                                        
                                                                              
n    	a               f(x)            f'(x)           h               x
0	3.000000        0.025077	  19.955679 	0.000000	    3.052632
1	3.052632        0.000013        19.932667       0.001257        3.051375
2     3.051375        -0.000001       19.932653       0.000001        3.051374
x=3.051374                                                                    
								     
