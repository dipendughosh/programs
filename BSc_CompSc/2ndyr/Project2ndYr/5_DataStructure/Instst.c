//insertion sort
#include<stdio.h>
#include<conio.h>

void main()
{       //Declaring Variables and Functions
	int a[20],i,n;
	void ins_srt(int [],int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//Calling the Insertion sort function
	ins_srt(a,n);
		//Displaying the sorted array
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

//Insertion sort function is defined
void ins_srt(int a[],int n)
{       //Declaring Variables
	int i,j,item;
	//Insertion sort logic
	for(i=0;i<n;i++)
	{	item=a[i];
		for(j=i;j>0;j--)
		{	if(item<a[j-1])
				a[j]=a[j-1];
			else
				break;
		}
		a[j]=item;
	}
}