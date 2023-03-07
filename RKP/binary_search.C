//To search a number using binary search method
#include<stdio.h>
#include<conio.h>

int main()
{   //Declaration of variables
	int beg,end,a[20],n,mid,i,item;
	clrscr();
	//Entering data
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements in sorted form:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter element to search:-");
	scanf("%d",&item);
	//Initializing variables for the loop
	beg=0;
	end=n-1;
	while(beg<=end)
	{	//Calculating the middle index
		mid=(beg+end)/2;
		//Checking if the entered data is at this position
		if(item==a[mid])
			break;
		//If the entered number is less then this part will be executed
		else if(item<a[mid])
			end=mid-1;
		//If the entered number is more then this part will be executed
		else
			beg=mid+1;
	}
	//Displaying the position of the number if present else displaying abscent
	if(beg<=end)
		printf("\nElement is at %d position",mid+1);
	else
		printf("\nElement not found");
	getch();
	return(0);
}

