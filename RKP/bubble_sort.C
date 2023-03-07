//Sorting a given list of integers using Bubble sort technique
#include<stdio.h>
#include<conio.h>

int main()
{   //Declaring variables
	int a[20],i,n;
	//Declaring function prototype
	void bub_srt2(int [],int);
//	clrscr();
	//Entering data
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//Calling the bubble sort function
	bub_srt2(a,n);
	//Displaying the sorted list
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
	return(0);
}

//Function declaration
void bub_srt2(int a[],int n)
{	//Declaring function's local variables
	int t,i,j;
	//Outer loop for how many times the inner loop should be executed
	for(i=0;i<n-1;i++)
	{	//Inner loop for sorting the list
		for(j=0;j<n-1-i;j++)
		{	if(a[j]>a[j+1])
			{	t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
