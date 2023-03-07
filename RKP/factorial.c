//Factorial of n
#include<stdio.h>
#include<conio.h>

int main()
{   //Declaring function prototype and variables
	int fact(int);
	int s,n;
//	clrscr();
	//Entering data
	printf("Enter number ");
	scanf("%d",&n);
	//Calling the function and displaying the result
	s=fact(n);
	printf("factorial of %d is %d\n",n,s);
	getch();
	return(0);
}

//Function declaration
int fact(int x)
{	//Declaring local variables
	int i,f=1;
	//Loop for calculating the factorial
	for(i=1;i<=x;i++)
		f=f*i;
	//Returning the result
	return f;
}

