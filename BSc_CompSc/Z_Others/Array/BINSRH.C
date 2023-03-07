#include<stdio.h>
#include<conio.h>

void main()
{       int beg,end,a[20],n,mid,i,item;
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements in sorted form:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter element to search:-");
	scanf("%d",&item);
	beg=0;
	end=n-1;
	while(beg<=end)
	{	mid=(beg+end)/2;
		if(item==a[mid])
			break;
		else if(item<a[mid])
			end=mid-1;
		else
			beg=mid+1;
	}
	if(beg<=end)
		printf("\nElement is at %d position",mid+1);
	else
		printf("\nElement not found");
	getch();
}

