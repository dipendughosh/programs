//merging and sorting array

#include<stdio.h>
#include<conio.h>

void main()
{
	int a[20],b[20],merge[50],n,m,i,j,k;
	clrscr();
	printf("\nEnter no of elements of 1st array: ");
	scanf("%d",&n);
	printf("\nEnter the elements of 1st array in sorted order: ");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]= ",i);
		scanf("%d", &a[i]);
	}
	printf("\nEnter no of elements of 2nd array: ");
	scanf("%d",&m);
	printf("\nEnter the elements of 2nd array in sorted order: ");
	for(i=0;i<m;i++)
	{
		printf("\nb[%d]= ",i);
		scanf("%d", &b[i]);
	}

	//merging
	/*for(i=0;i<n;i++)
	{
		merge[i]=a[i];
	}
	for(j=i,k=0;j<m+n,k<m;j++,k++)
		merge[j]=b[k];
	for(i=0;i<n+m;i++)
		printf("\nmerge[%d]=%d", i,merge[i]);*/

	//i=a[], j=b[], k=merge[]
	i=j=k=0;
	//printf("\n i=%d, j=%d, k=%d", i,j,k);
	while(i<n && j<m && k<n+m)
	{
		printf("\nTesing\n");
		if(a[i]<b[j])
		{
			merge[k]=a[i];
			i++ ;
			k++;
		}
		else
		{
			merge[k]=b[j];
			j++;
			k++;
		}
	}
		printf("\nTesing1\n");
	if(i==n)
	{
			printf("\ninsert j");
		while(j<m)
		{
			merge[k]=b[j];
				printf("\ninsert j");
			j++;
			k++;
		}
	}
	if(j==m)
	{
		while(i<n)
		{
			merge[k]=a[i];
			printf("\ninsert i");
			i++;
			k++;
		}
	}
	printf("\nAfter merging--");
	for(i=0;i<n+m;i++)
		printf("\nmerge[%d]=%d", i,merge[i]);

	getch();
}
