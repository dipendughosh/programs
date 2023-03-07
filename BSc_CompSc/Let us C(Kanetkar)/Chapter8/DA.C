#include<stdio.h>
#include<conio.h>

void main()
{       int a[25],i,x,y=0;
	clrscr();
	printf("\nA");
	for(i=0;i<25;i++)
		scanf("%d",&a[i]);
	printf("\nEnter number to search-");
	scanf("%d",&x);
	for(i=0;i<25;i++)
	{	if(x==a[i])
			y++;
	}
	if(y==0)
		printf("\n%d does not exist in the array ",x);
	else
		printf("\n%d exist in the array %d times ",x,y);
	getch();
}

