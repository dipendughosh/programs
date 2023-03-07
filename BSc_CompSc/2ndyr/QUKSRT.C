//quick sort
#include<stdio.h>
#include<conio.h>

void swap(int *a,int *b)
{	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void main()
{       int a[20],i,n;
	void qk_srt(int [],int,int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qk_srt(a,0,n);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

void qk_srt(int a[],int m,int n)
{	int i,j,k;
	if(m<n)
	{	i=m;
		j=n;
		k=a[m];
		do
		{	do
			{	i++;
			}while(a[i]<k);
			do
			{	j--;
			}while(a[j]>k);
			if(i<j)
				swap(&a[i],&a[j]);
		}while(i<j);
		swap(&a[m],&a[j]);
		qk_srt(a,m,j-1);
		qk_srt(a,j+1,n);
	}
}


