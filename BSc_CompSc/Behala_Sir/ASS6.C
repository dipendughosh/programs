#include<stdio.h>
#include<conio.h>

void main()
{       int a[100],i,x,y,n;
	clrscr();
	printf("Enter n - ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	printf("Enter a[%d] ",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
		printf("\na[%d] = %d",i,a[i]);
	printf("\nEnter number to insert ");
	scanf("%d",&x);
	for(i=n-1;i>=0;i--)
	{	if(a[i]>=x)
		{	a[i+1]=a[i];
			y=i;
		}
	}
	a[y]=x;
	for(i=0;i<n+1;i++)
		printf("\na[%d] = %d",i,a[i]);
	getch();
}

