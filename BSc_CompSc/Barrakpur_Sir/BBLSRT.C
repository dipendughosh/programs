//bubble sort
#include<stdio.h>
#include<conio.h>


void main()
{       int a[10],i,j,temp;
	clrscr();
	printf("\nEnter elements\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	{	for(j=i+1;j<10;j++)
		{	if(a[i]>a[j])
			{	temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);

	getch();
}

