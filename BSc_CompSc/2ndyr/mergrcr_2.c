#include<stdio.h>
#include<conio.h>

void mergesort(int [],int,int,int);
void merge(int [],int,int,int,int);

void main()
{
	int a[10],x,i,lb,ub;
	printf("Enter number of items :- ");
	scanf("%d",&x);
	printf("Enter the elements :- \n");
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	lb=0;
	ub=x-1;
	mergesort(a,lb,ub,x);
	printf("\nSorted list:-\n");
	for(i=0;i<x;i++)
		printf("%d\t",a[i]);
}

void mergesort(int a[],int lb,int ub,int x)
{
	int m;
	if(lb<ub)
	{
		m=(int)((lb+ub)/2);
		mergesort(a,lb,m,x);
		mergesort(a,m+1,ub,x);
		merge(a,lb,ub,m,x);
	}
}

void merge(int a[],int lb,int ub,int m,int x)
{
	int b[10],n,j,k=lb,p;
	for(n=lb,j=m;n<=m && j<=ub;)
	{
		if(a[n]<a[j])
			b[k++]=a[n++];
		else
			b[k++]=a[j++];
	}
	while(n<=m)
		b[k++]=a[n++];
	while(j<=ub)
		b[k++]=a[j++];
	for(p=lb;p<=ub;p++)
		a[p]=b[p];
}