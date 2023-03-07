#include<stdio.h>
#include<conio.h>

void merg(int [],int,int,int);

void main()
{	int a[100],n;
	int recur_merg_sort(int [],int,int);
	void display(int [],int);
	void insert(int [],int);
	clrscr();
	printf("Enter size of array - ");
	scanf("%d",&n);
	insert(a,n);
	printf("\nBefore Sorting-\n");
	display(a,n);
	recur_merg_sort(a,0,n-1);
	printf("\nSorted Array is-\n");
	display(a,n);
	getch();

}

int recur_merg_sort(int a[],int start,int finish)
{	int mid;
	if(start==finish)
		return(0);
	mid=(int)(start+finish)/2;
	recur_merg_sort(a,start,mid);
	recur_merg_sort(a,mid+1,finish);
	merg(a,start,mid+1,finish);
	return (0);
}

void merg(int a[],int first,int second,int third)
{	int temp[100],l,i,j;
	i=first;
	j=second;
	l=0;
	while((i<second)&&(j<=third))
	{	if(a[i]<=a[j])
		{	l=l+1;
			temp[l]=a[i];
			i=i+1;
		}
		else
		{	l=l+1;
			temp[l]=a[j];
			j=j+1;
		}
	}
	if(i==second)
	{	while(j<=third)
		{	l=l+1;
			temp[l]=a[j];
			j=j+1;
		}
	}
	else
	{	while(i<second)
		{	l=l+1;
			temp[l]=a[i];
			i=i+1;
		}
	}
	for(i=1;i<=l;i++)
	{	a[first-1+i]=temp[i];
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
