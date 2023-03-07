//Bubble sort using flag
#include<stdio.h>
#include<conio.h>

void main()
{       //Declaring Variables and Functions
	int a[20],i,n;
	void bub_srt1(int [],int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//Calling the bubble sort function
	bub_srt1(a,n);
	//Displaying the sorted array
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

//Bubble sort function is defined
void bub_srt1(int a[],int n)
{       //Declaring Variables
	int t,i,j,flag=0;
	//Bubble sort logic
	for(i=0;i<n-1 && flag==0;i++)
	{	for(j=0;j<n-1-i;j++)
		{	if(a[j]>a[j+1])
			{       flag=0;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}