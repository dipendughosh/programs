//To find maximum and minimum from a given list
#include<stdio.h>
#include<conio.h>

int main()
{//	clrscr();
	//Declaring variables
	int a[20],max,min,i,n;
	//Enter data
	printf("Enter number of numbers ");
	scanf("%d",&n);
	printf("Enter array ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//The first number is taken as default minimum and default maximum
	max=a[0];
	min=a[0];
	//Loop to find the minimum and maximum from the list entered
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	//Displaying the minimum and the maximum of the list
	printf("\nMaximum number = %d\nMinimum number = %d",max,min);
	getch();
	return(0);
}