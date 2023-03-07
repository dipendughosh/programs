//merge sort
#include<stdio.h>
#include<conio.h>


void main()
{       //Declaring Variables and Functions
	int a[20],i,n;
	void mrg_srt(int [],int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//Calling the Merge sort function
	mrg_srt(a,n);
	//Displaying the sorted array
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

//Merge sort function is defined
void mrg_srt(int a[],int n)
{       //Declaring Variables
	int la,ua,lb,ub,aux[50],i,j,size,k;
	//Merge sort logic
	size=1;
	while(size<n)
	{	k=0;
		la=0;
		while(la+size<=n)
		{	lb=la+size;
			ua=lb-1;
			ub=(lb+size-1)<n?lb+size-1:n-1;
			for(i=la,j=lb;i<=ua && j<=ub;k++)
			{	if(a[i]<a[j])
				{	aux[k]=a[i];
					i++;
				}
				else
				{	aux[k]=a[j];
					j++;
				}
			}
			while(i<=ua)
			{	aux[k]=a[i];
				k++;
				i++;
			}
			while(j<=ub)
			{	aux[k]=a[j];
				k++;
				j++;
			}
			la=ub+1;
		}
		for(i=0;i<n;i++)
			a[i]=aux[i];
		size=size*2;
	}
}
