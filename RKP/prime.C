//check if a number is prime
#include<stdio.h>
#include<conio.h>

int main()
{   //Declaring variables
	int i,j,b,c,k,n,flag;
//	clrscr();
	//Entering data
	printf("Enter number to check - ");
	scanf("%d",&n);
	//Initializing variables for the loop which will find out if the entered number is a prime
	c=0;
	for(i=1;i<=(n/2);i++)
	{	b=n%i;
		if(b==0)
			++c;
	}
	//Displaying entered number is prime or not
	if(c==1)
		printf("\n%d is a prime number",n);
	else
		printf("\n%d is not a prime number",n);

	getch();
	return(0);
}

