//delete from array

#include<stdio.h>
#include<conio.h>

void main()
{
	int a[20],n,m,j,i;
	clrscr();
	printf("\nEnter no of elements: ");
	scanf("%d",&n);
	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]= ",i);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the no. which you want to delete: ");
	scanf("%d", &m);
	for(i=0;i<n;i++)
	{
		if(a[i]==m)
		{
			j=i;
			while(j<n)
			{
				a[i]=a[i+1];
				i++;
				j++;
			}
		}
	}
	printf("\nAfter deletion--");
	for(i=0;i<n-1;i++)
		printf("\na[%d]=%d",i,a[i]);
	getch();
}