//sort all
#include<stdio.h>
#include<conio.h>
#include<math.h>

void swap(int *a,int *b)
{	int c;
	c=*a;
	*a=*b;
	*b=c;
}

void insert(int a[],int n,int j)
{	int m,k,temp,ptr,i;
	for(k=0;k<j;k++)
	{	m=1;
		while((m*j)<n)
		{	i=k+(m*j);
			temp=a[i];
			for(ptr=k-j;ptr>=0 && a[ptr]>temp;ptr=ptr-j)
				a[ptr+j]=a[ptr];
			a[ptr]=temp;
			m=m+1;
		}
	}
}

void merge(int a[],int f,int m,int l)
{       int c[100],i=f,j=m,k=0;
	while(i<m && j<l)
	{	if(a[i]<a[j])
		{	c[k]=a[i];
			i++;
		}
		else
		{	c[k]=a[j];
			j++;
		}
		k++;
	}
	if(i<m)
	{	while(i<m)
		{	c[k]=a[i];
			k++;
			i++;
		}
	}
	else if(j<l)
	{	while(j<l)
		{	c[k]=a[j];
			j++;
			k++;
		}
	}
	for(i=0;i<k;i++)
		a[i]=c[i];
}

void main()
{       int a[100],n,i,c,incr[]={5,3,1},inc=3,a2[100],m,d[100];
	void insert1(int [],int);
	void bubble1(int [],int);
	void bubble2(int [],int);
	void selection(int [],int);
	void insertion(int [],int);
	void radix(int [],int);
	void quick(int [],int,int);
	void shell(int [],int,int [],int);
	void merge1(int [],int [],int [],int,int);
	void merge2(int [],int,int);
	void display(int [],int);
	do
	{	clrscr();
		printf("\tMENU\n");
		printf("\t1.Bubble Sort1\n");
		printf("\t2.Bubble Sort2\n");
		printf("\t3.Selection Sort\n");
		printf("\t4.Insertion Sort\n");
		printf("\t5.Radix Sort\n");
		printf("\t6.Quick Sort\n");
		printf("\t7.Shell Sort\n");
		printf("\t8.Merge Sort1\n");
		printf("\t9.Merge Sort2\n");
		printf("\t10.Exit");
		printf("\nEnter choice - ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				printf("Enter size of array - ");
				scanf("%d",&n);
				insert1(a,n);
				printf("\nBefore Sorting-\n");
				display(a,n);
				bubble1(a,n);
				printf("\nSorted Array is-\n");
				display(a,n);
				break;
			case 2:
				printf("Enter size of array - ");
				scanf("%d",&n);
				insert1(a,n);
				printf("\nBefore Sorting-\n");
				display(a,n);
				bubble2(a,n);
				printf("\nSorted Array is-\n");
				display(a,n);
				break;
			case 3:
				printf("Enter size of array - ");
				scanf("%d",&n);
				insert1(a,n);
				printf("\nBefore Sorting-\n");
				display(a,n);
				selection(a,n);
				printf("\nSorted Array is-\n");
				display(a,n);
				break;
			case 4:
				printf("Enter size of array - ");
				scanf("%d",&n);
				insert1(a,n);
				printf("\nBefore Sorting-\n");
				display(a,n);
				insertion(a,n);
				printf("\nSorted Array is-\n");
				display(a,n);
				break;
			case 5:
				printf("Enter size of array - ");
				scanf("%d",&n);
				insert1(a,n);
				printf("\nBefore Sorting-\n");
				display(a,n);
				radix(a,n);
				printf("\nSorted Array is-\n");
				display(a,n);
				break;
			case 6:
				printf("Enter size of array - ");
				scanf("%d",&n);
				insert1(a,n);
				printf("\nBefore Sorting-\n");
				display(a,n);
				quick(a,0,n-1);
				printf("\nSorted Array is-\n");
				display(a,n);
				break;
			case 7:
				printf("Enter size of array - ");
				scanf("%d",&n);
				insert1(a,n);
				printf("\nBefore Sorting-\n");
				display(a,n);
				shell(a,n,incr,inc);
				printf("\nSorted Array is-\n");
				display(a,n);
				break;
			case 8:
				printf("Enter size of array - ");
				scanf("%d",&n);
				insert1(a,n);
				printf("Enter size of 2nd array - ");
				scanf("%d",&m);
				insert1(a2,m);
				printf("\nBefore Sorting-\n");
				display(a,n);
				printf("\n");
				display(a2,m);
				merge1(a,a2,d,n,m);
				printf("\nSorted Array is-\n");
				display(d,n+m);
				break;
			case 9:
				printf("Enter size of array - ");
				scanf("%d",&n);
				insert1(a,n);
				printf("\nBefore Sorting-\n");
				display(a,n);
				merge2(a,0,n);
				printf("\nSorted Array is-\n");
				display(a,n);
				break;
			case 10:
				exit(0);
			default:
				printf("\nWrong Input");
				break;
		}
		getch();
	}while(1);
}

void insert1(int b[],int m)
{       int i;
	printf("Enter elements of array-\n");
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
}

void display(int b[],int m)
{	int i;
	for(i=0;i<m;i++)
		printf("%d\t",b[i]);
}

void bubble1(int b[],int m)
{       int i,j;
	printf("\nBubble Sort I\n");
	for(i=0;i<m-1;i++)
		for(j=i+1;j<m;j++)
			if(b[i]>b[j])
				swap(&b[i],&b[j]);
}

void bubble2(int b[],int m)
{       int i,flag=1;
	printf("\nBubble Sort II\n");
	while(flag!=0)
	{	flag=0;
		for(i=0;i<m-1;i++)
			if(b[i]>b[i+1])
			{	swap(&b[i],&b[i+1]);
				flag=1;
			}
		m--;
	}
}

void selection(int b[],int m)
{       int i,j,min,temp;
	printf("\nSelection Sort\n");
	for(i=0;i<m-1;i++)
	{	min=i;
		for(j=i+1;j<m;j++)
			if(b[j]<b[min])
				min=j;
		if(min!=i)
		{	temp=b[i];
			b[i]=b[min];
			b[min]=temp;
		}
	}
}

void insertion(int b[],int m)
{       int i,j,temp;
	printf("\nInsertion Sort\n");
	for(i=1;i<m;i++)
	{       temp=b[i];
		j=i-1;
		while(temp<b[j] && j>=0)
		{	b[j+1]=b[j];
			j=j-1;
		}
		b[j+1]=temp;
	}
}

void radix(int b[],int m)
{	struct element
	{	int data[100];
		int cnt;
	}ele[100];
	int i,j,x,k,a,n;
	printf("\nRadix Sort");
	for(i=0;i<100;i++)
		ele[i].cnt=0;
	for(i=0;i<3;i++)
	{	for(j=0;j<m;j++)
		{	n=b[j];
			a=pow(10,i+1);
			n=b[j]%a;
			a=pow(10,i+1);
			n=n/a;
			ele[n].data[ele[n].cnt++]=b[j];
		}
		x=0;
		for(j=0;j<m;j++)
		{	for(k=0;k<ele[x].cnt;k++)
				b[j]=ele[x].data[k];
			x++;
		}
	}
}

void quick(int b[],int lb,int ub)
{	int pivot,i,j;
	if(lb<ub)
	{	pivot=b[lb];
		i=lb;
		j=ub;
		while(i<j)
		{	while(b[i]<=pivot)
				i++;
			while(b[j]>=pivot)
				j--;
			if(i<j)
				swap(&(b[i]),&(b[j]));
		}
		swap(&(b[lb]),&(b[j]));
		quick(b,lb,j-1);
		quick(b,j+1,ub);
	}
	return;
}

/*{	int i,j,pivot,x,y;
	i=lb;
	j=ub-1;ub--;
	if(lb==ub)
		return;
	while(lb<ub)
	{       pivot=b[i];
		while(i<j)
		{	while(pivot>b[i])
				i++;
			while(pivot<b[j])
				j--;
			if(i<j)
			{       x=b[i];
				y=b[j];
				printf("\n%d %d",x,y);
				swap(&x,&y);
			}
		}
		x=b[j];
		swap(&pivot,&x);
	}
	quick(b,lb,j-1);
	quick(b,j+1,ub);
	return;
}*/

void shell(int b[],int m,int incr[],int inc)
{	int i;
	for(i=0;i<inc;i++)
		insert(b,m,incr[i]);
}

void merge1(int a[],int b[],int c[],int n,int m)
{       int i=0,j=0,k=0;
	while(i<n && j<m)
	{	if(a[i]<b[j])
		{	c[k]=a[i];
			i++;
		}
		else
		{	c[k]=b[j];
			j++;
		}
		k++;
	}
	if(i<n)
	{	while(i<n)
		{	c[k]=a[i];
			k++;
			i++;
		}
	}
	else if(j<m)
	{	while(j<m)
		{	c[k]=b[j];
			j++;
			k++;
		}
	}
}

void merge2(int b[],int f,int l)
{	int m;
	if(l==f)
		return;
	m=(int)(l+f)/2;
	merge2(b,f,m);
	merge2(b,(m+1),l);
	merge(b,f,m,l);
}
