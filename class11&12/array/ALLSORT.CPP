#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<process.h>

void swap(int &,int &);
void showarr(int a[],int n)
{	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<endl;
}

void main()
{       clrscr();
	int cho;
	int a[]={1,10,8,6,5,3,2,4,7,9};
	int b[]={11,16,19,20,18,12,13,15,14,17};
	void insert_sort(int []);
	void selection_sort(int []);
	void bubble_sort(int []);
	void merge_sort(int [],int []);
	void showarr(int [],int );
	cout<<"\n\tMENU";
	cout<<"\n1.Insertion Sort";
	cout<<"\n2.Selection Sort";
	cout<<"\n3.Bubble Sort";
	cout<<"\n4.Merge Sort";
	cout<<"\n5.Exit";
	cout<<"\nEnter choice->";
	cin>>cho;
	switch(cho)
	{	case 1:
			insert_sort(a);
		break;
		case 2:
			selection_sort(a);
		break;
		case 3:
			bubble_sort(a);
		break;
		case 4:
			merge_sort(a,b);
		break;
		case 5:
			cout<<"\nEXITING...............";
			getche();
			exit(0);
		break;
		default:
			cout<<"\nWRONG CHOICE";
		break;
	}
	getche();
}

void insert_sort(int a[])
{   	cout<<"\nInsertion sort\n\n";
	int n=10,i;
	for (i=1;i<n;i++)
	{	int x=a[i];
		int j=i;
		/*showarr(a,10);
		getche();*/
		while (j>0 && a[j-1]>x)
		{	a[j--]=a[j-1];
		}
		a[j]=x;
	}
	showarr(a,10);
	cout<<"\nend\n";
}

void selection_sort(int a[])
{   	cout<<"\nSelection sort\n\n";
	int n=10,i;
	for (i=1;i<n;i++)
	{	int k=0;
		for (int j=1;j<=n-i;j++)
			if (a[j]>a[k])
				k=j;
		/*showarr(a,10);
		getche();*/
		swap(a[k],a[n-i]);
	}
	showarr(a,10);
	cout<<"\nend\n";
}

void swap(int &x,int &y)
{	int temp=x;
	x=y;
	y=temp;
}

void bubble_sort(int a[])
{   	cout<<"\nBUBBLE SORT\n";
	int n=10;
	for(int i=0;i<9;i++)
	{	for(int j=i+1;j<10;j++)
		{	if(a[i]>=a[j])
			{   	/*showarr(a,10);
				getche();*/
				swap(a[i],a[j]);
			}
		}
	}
	showarr(a,10);
	cout<<"\nend\n";
}

void merge_sort(int a[],int b[])
{   	cout<<"\nMerge sort\n\n";
	int i,j,k,temp,z=0,m=10,n=10,c[20],x=20;
	for(i=0;i<m-1;i++)
	{	for(j=i+1;j<m;j++)
		{	if(a[i]<=a[j])
			{	temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{	for(j=i+1;j<n;j++)
		{	if(b[i]<=b[j])
			{	temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	for(i=0;i<m;i++)
		c[i]=a[i];
	j=i;
	for(i=0;i<n;i++)
	{	c[j]=b[i];
		j++;
	}
	for(i=0;i<x-1;i++)
	{	for(j=i+1;j<x;j++)
		{	if(c[i]<=c[j])
			{	temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
	}
	for(i=0;i<x-1;i++)
	{	for(j=i+1;j<x;j++)
		{	if(c[i]==c[j])
			{	for(k=j;k<x;k++)
				{	c[k]=c[k+1];
				}
				x--;
			}
		}
	}
	showarr(c,20);
}

