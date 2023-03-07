#include<conio.h>
#include<iostream.h>
#include<stdio.h>

void swap(int &,int &);
void showarr(int a[])
{	for (int i=0;i<10;i++)
		cout<<a[i]<<' ';

	cout<<endl;
}

void main()
{   clrscr();
	int a[]={2,5,0,9,31,6,8,11,4,7};
	void insert_sort(int []);
	void selection_sort(int []);
	void bubble_sort(int []);
	void showarr(int []);
//	insert_sort(a);
//	selection_sort(a);
	bubble_sort(a);
	getch();
}

void insert_sort(int a[])
{   cout<<"Insertion sort\n";
	showarr(a);
	int n=10,i;
	for (i=1;i<n;i++)
	{	int x=a[i];
		int j=i;
		showarr(a);
		while (j>0 && a[j-1]>x)
		{	a[j--]=a[j-1];
		}
		a[j]=x;
	}
	showarr(a);
}

void selection_sort(int a[])
{   cout<<"\nSelection sort";
	cout<<endl;
	showarr(a);
	int n=10,i;
	for (i=1;i<n;i++)
	{	int k=0;
		showarr(a);
		for (int j=1;j<=n-i;j++)
			if (a[j]>a[k])
				k=j;
		swap(a[k],a[n-i]);
	}

}

void swap(int &x,int &y)
{	int temp=x;
	x=y;
	y=temp;
}

void bubble_sort(int a[])
{	int n=10;
	showarr(a);
	for(int i=1;i<9;i++)
	{	for(int j=0;j<10-i;j++)
		{	if(a[j]>a[j+1])
			{	swap(a[j],a[j+1]);
				showarr(a);getch();
			}
		}
	}
	showarr(a);
}

