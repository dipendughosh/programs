//Fibonacci numbers up to n terms
#include<stdio.h>
#include<conio.h>


void main()
{       //Declaring variables and function
	int i,a=0,b=1,c,n;
	//clrscr();
	printf("Enter n : ");
	scanf("%d",&n);
	printf("0 1");
	for(i=2;i<n;i++)
	{      	c=a+b;
		a=b;
		b=c;
		printf(" %d",c);
	}
	getch();
}

