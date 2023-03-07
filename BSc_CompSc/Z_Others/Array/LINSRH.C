#include<stdio.h>
#include<conio.h>

void main()
{       int a[20],i,n,item;
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter element to search:-");
	scanf("%d",&item);
	for(i=0;i<n;i++)
		if(item==a[i])
			break;
	if(i<n)
		printf("\nElement found at %d position.",i+1);
	else
		printf("\nElement not found");
	getch();
}

