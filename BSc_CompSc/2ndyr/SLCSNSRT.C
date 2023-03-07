//selection sort
#include<stdio.h>
#include<conio.h>


void main()
{       int i,a[20],n;
	void sel_srt(int [],int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sel_srt(a,n);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

void sel_srt(int a[],int n)
{       int i,j,pos,min;
	for(i=0;i<=n;i++)
	{	min=a[i];
		pos=i;
		for(j=i+1;j<=n-1;j++)
		{	if(min>a[j])
			{	min=a[j];
				pos=j;
			}
		}
		a[pos]=a[i];
		a[i]=min;
	}
}