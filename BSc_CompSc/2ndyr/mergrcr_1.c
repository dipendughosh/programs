//merge sort recursive
#include<stdio.h>
#include<conio.h>

void merge(int a[],int p,int q,int r)
{
	int n1,n2,left[10],right[10],i,j,k;
	n1=q-p+1;
	n2=r-q;
	for(i=1;i<=n1;i++)
		left[i]=a[p+i-1];
	for(j=1;j<=n2;j++)
		right[j]=a[q+j];
	i=1;
	j=1;
	for(k=p;k<=r;k++)
	{
		if(left[i]<=right[j])
			a[k]=left[i++];
		else
			a[k]=right[j++];
	}
}

void mrg_srt(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mrg_srt(a,p,q);
		mrg_srt(a,q+1,r);
		merge(a,p,q,r);
	}
}



void main()
{   //Declaring Variables and Functions
	int a[20],i,n;
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//Calling the Merge sort function
	mrg_srt(a,1,n);
	//Displaying the sorted array
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);

}



