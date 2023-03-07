//Series
#include<conio.h>
#include<stdio.h>

int fact(int);

int main()
{	//clrscr();
	//Declaring variables
	int i;
	float n,s=0,a;
	//Entering data
	printf("Enter value of n");
	scanf("%f",&n);
	//Calculating the sum of the series
	for(i=1;i<=n;i++)
	{	a=i%2;
		if(a == 0)
			s=s-(i/fact(i));
		else
			s=s+(i/fact(i));
	}
	//Displaying the sum of the series
	printf("sum = %ld",s);
	getche();
	return(0);
}

//Calculating the factoial of the number
int fact(int a)
{	int i,f=1;
	for(i=1;i<=a;i++)
		f=(f*i);
	return f;
}