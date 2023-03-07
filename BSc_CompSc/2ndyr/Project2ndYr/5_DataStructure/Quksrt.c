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
{       //Declaring Variables and Functions
	int a[20],i,n;
	void qk_srt(int [],int,int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//Calling the Quick sort function
	qk_srt(a,0,n);
	//Displaying the sorted array
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

//Quick sort function is defined
void qk_srt(int a[],int m,int n)
{       //Declaring Variables
	int i,j,k;
	//Quick sort logic
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


