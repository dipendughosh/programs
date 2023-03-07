#include<stdio.h>
#include<conio.h>


void main()
{       int a[10],i,j,min,x;
	clrscr();
	printf("\nEnter elements-\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	{       min=a[0];
		for(j=0;j<10;j++)
		{	if(min>=a[j])
			{	min=a[j];
				x=j;
			}
		}
		printf("\n%d %d\t",x,a[x]);
		a[x]=999;
		for(j=0;j<10;j++)
			printf("\t%d",a[j]);
	}
	getch();
}

