//bubble sort without using flag
#include<stdio.h>
#include<conio.h>

void main()
{       int a[20],i,n;
	void bub_srt2(int [],int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bub_srt2(a,n);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

void bub_srt2(int a[],int n)
{	int t,i,j;
	for(i=0;i<n-1;i++)
	{	for(j=0;j<n-1-i;j++)
		{	if(a[j]>a[j+1])
			{	t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
