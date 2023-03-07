//insertion sort
#include<stdio.h>
#include<conio.h>

void main()
{	int a[20],i,n;
	void ins_srt(int [],int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ins_srt(a,n);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

void ins_srt(int a[],int n)
{       int i,j,item;
	for(i=0;i<n;i++)
	{	item=a[i];
		for(j=i;j>0;j--)
		{	if(item<a[j-1])
				a[j]=a[j-1];
			else
				break;
		}
		a[j]=item;
	}
}