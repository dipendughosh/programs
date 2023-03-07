#include<stdio.h>
#include<conio.h>

void main()
{       int a[10],i,min;
	clrscr();
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	min=a[0];
	for(i=1;i<10;i++)
	{	if(a[i]<min)
			min=a[i];
	}
	printf("\nMin=%d",min);
	getch();
}

