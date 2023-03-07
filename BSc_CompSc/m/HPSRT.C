//Heap sort
#include<stdio.h>
#include<conio.h>

void main()
{       //Declaing Variables and functions
	void crheap(int [],int);
	void heapsort(int [],int);
	int a[20],i,n;
	clrscr();
	printf("Enter the size of the array:-");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n");
	//Calling the Heap Create function
	crheap(a,n);
	//Calling the Heap Sort function
	heapsort(a,n);
	//Displaying the sorted array
	printf("\nArray after sorting:-\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

//Heap Create function is defined
void crheap(int a[],int n)
{	int i,j,key,k;
	//Heap Create logic
	for(k=1;k<n;++k)
	{	i=k;
		key=a[k];
		j=(int)(i/2);
		while((i>0) && (key>a[j]))
		{	a[i]=a[j];
			i=j;
			j=(int)(i/2);
			if(j<0)
				j=0;
		}
		a[i]=key;
	}
}

//Heap Sort function is defined
void heapsort(int a[],int n)
{	int k,temp,i,j,key;
	//Heap Sort logic
	for(k=n-1;k>=1;--k)
	{	temp=a[0];
		a[0]=a[k];
		a[k]=temp;
		i=0;
		key=a[0];
		j=1;
		if((j+1)<k)
			if(a[j+1]>a[j])
				j=j+1;
		while((j<=(k-1)) && (a[j]>key))
		{	a[i]=a[j];
			i=j;
			j=2*i;
			if((j+1)<k)
			{	if(a[j+1]>a[j])
					j=j+1;
				else if(j>n)
					j=n;
			}
			a[i]=key;
		}
	 }
}

