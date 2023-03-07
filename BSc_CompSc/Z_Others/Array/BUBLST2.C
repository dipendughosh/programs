#include<stdio.h>
#include<conio.h>

void main()
{       int a[20],t,i,j,n,flag=0;
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1 && flag==0;i++)
	{	for(j=0;j<n-1-i;j++)
		{	if(a[j]>a[j+1])
			{       flag=0;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);

	getch();
}

