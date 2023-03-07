//Heap
#include<stdio.h>
#include<conio.h>

void main()
{   //Declaing Variables and functions
	void crheap(int [],int);
	int a[20],i,n,x,y;
	printf("Enter the size of the array:-");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter number to enter :- ");
	scanf("%d",&x);
	printf("\nEnter position where to enter the number :- ");
	scanf("%d",&y);
	printf("\n");
	a[y]=x;
	//Calling the Heap Create function
	crheap(a,n);
	//Displaying the sorted array
	printf("\nArray after recreating heap:-\n");
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
		j=(int)((i-1)/2);
		while((i>0) && (key>a[j]))
		{	a[i]=a[j];
			i=j;
			j=(int)((i-1)/2);
			if(j<0)
				j=0;
		}
		a[i]=key;
	}
}
