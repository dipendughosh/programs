//Quick Sort
#include<stdio.h>
#include<conio.h>
void main()
{       int a[100],n;
	void quick_sort(int [],int,int);
	void display(int [],int);
	void insert(int [],int);
	clrscr();
	printf("Enter size of array - ");
	scanf("%d",&n);
	insert(a,n);
	printf("\nBefore Sorting-\n");
	display(a,n);
	quick_sort(a,0,n-1);
	printf("\nSorted Array is-\n");
	display(a,n);
	getch();
}
void quick_sort(int a[],int lb,int ub)
{	int i,j,temp,key;
	if(lb<ub)
	{       i=lb;
		j=ub+1;
		key=a[lb];
		do
		{       do
			{	i=i+1;
			}while(a[i]<key);
			do
			{	j=j-1;
			}while(a[j]>key);
			if(i<j)
			{	temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}while(i<j);
		temp=a[j];
		a[j]=a[lb];
		a[lb]=temp;
		quick_sort(a,lb,j-1);
		quick_sort(a,j+1,ub);
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
