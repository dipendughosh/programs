//Fibonacci series upto n
#include<stdio.h>
#include<conio.h>

int main()
{   //Declaring variables
	int n1,n,a=1,b=1,c=0,i,flag=0;
//	clrscr();
	//Entering data
	printf("Enter range ");
	scanf("%d",&n);
	//Displaying the first two terms of the series
	printf("%d\t%d",a,b);
	//Loop to calculate the next terms and displaying them
	for(i=2;i<n;i++)
	{   c=a+b;
		printf("\t%d",c);
		a=b;
		b=c;
	}
	getch();
	return(0);
}

