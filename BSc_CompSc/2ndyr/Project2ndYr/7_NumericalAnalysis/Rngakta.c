//Runga Kutta Method to solve a given differential equation
#include<stdio.h>
#include<conio.h>

//Given function
float f(float a,float b)
{	return(a*b);
}

void main()
{       //Declaring variables
	float x[20],y[20],h,k1,k2,k3,k4,k,xn,i;
	int j;
	clrscr();
	printf("\nEnter X0-");
	scanf("%f",&x[0]);
	printf("\nEnter Y0-");
	scanf("%f",&y[0]);
	printf("\nEnter h-");
	scanf("%f",&h);
	printf("\nEnter xn-");
	scanf("%f",&xn);
	//Runga-Kutta Method Logic
	printf("\tX\t\tY");
	for(i=0.0,j=0;i<=xn;i=i+h,j++)
	{       k1=h*f(x[j],y[j]);
		k2=h*f(x[j]+h/2,y[j]+k1/2);
		k3=h*f(x[j]+h/2,y[j]+k2/2);
		k4=h*f(x[j]+h,y[j]+k3);
		k=(k1+2*k2+2*k3+k4)/6;
		y[j+1]=y[j]+k;
		x[j+1]=x[j]+h;
		printf("\n\t%f\t\t%f",x[j],y[j]);
	}
	getch();
}

Output:-

Enter X0-0                                                               
Enter Y0-2                                                               
Enter h-.2                                                                 
Enter xn-.8                                                               
        X                           Y                                                     
        0.000000                2.000000                                      
        0.200000                2.040403                                      
        0.400000                2.166574                                      
        0.600000                2.394434                                      
        0.800000                2.754253                                      
