//Insertion Sort
#include<stdio.h>
#include<conio.h>
void main()
{
	int a[100],n;
	void insertion(int [],int);
	void display(int [],int);
	void insert(int [],int);
	clrscr();
	printf("Enter size of array - ");
	scanf("%d",&n);
	insert(a,n);
	printf("\nBefore Sorting-\n");
	display(a,n);
	insertion(a,n);
	printf("\nSorted Array is-\n");
	display(a,n);
	getch();
}

void insertion(int b[],int m)
{       int i,j,temp;
	printf("\nInsertion Sort\n");
	for(i=1;i<m;i++)
	{       temp=b[i];
		j=i-1;
		while(temp<b[j] && j>=0)
		{	b[j+1]=b[j];
			j=j-1;
		}
		b[j+1]=temp;
	}
}

void insert(int b[],int m)
{       int i;
	printf("Enter elements of array-\n");
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
}

void display(int b[],int m)
{	int i;
	for(i=0;i<m;i++)
		printf("%d\t",b[i]);
}
