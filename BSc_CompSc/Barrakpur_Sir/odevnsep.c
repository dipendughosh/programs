//odd ,even separate
#include<stdio.h>
#include<conio.h>


void main()
{       int a[10],b[10],c[10],i,x=0,y=0;
	clrscr();
	printf("Enter array elements-:\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	{	if(a[i]%2==0)
		{	b[x]=a[i];
			x++;
		}
		else
		{	c[y]=a[i];
			y++;
		}
	}
	printf("\nEven numbers are:-");
	for(i=0;i<x;i++)
		printf("%d\t",b[i]);
	printf("\nOdd numbers are:-");
	for(i=0;i<y;i++)
		printf("%d\t",c[i]);

	getch();
}

