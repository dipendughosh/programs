#include<stdio.h>
#include<conio.h>

void main()
{       int a[20],i,x,y;
	clrscr();
	for(i=0;i<10;i++)
	{	printf("Enter a[%d] ",i);
		scanf("%d",&a[i]);
	}
	printf("\nEnter number to insert with ");
	scanf("%d",&x);
	printf("\nEnter position where to insert  ");
	scanf("%d",&y);
	for(i=9;i>y;i--)
		a[i+1]=a[i];
	a[y]=x;
	for(i=0;i<11;i++)
		printf("\na[%d] = %d",i,a[i]);
	getch();
}

