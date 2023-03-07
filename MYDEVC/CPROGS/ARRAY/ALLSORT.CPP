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
{   int cho;
	int a[]={2,5,18,9,13,6,8,11,4,7};
    int b[]={14,15,1,20,3,10,12,16,19,17};
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
    {   case 1:
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
{   cout<<"\nInsertion sort\n\n";
 	int n=10,i;
	for (i=1;i<n;i++)
	{	int x=a[i];
		int j=i;
        showarr(a,10);
        getche();
        while (j>0 && a[j-1]>x)
		{	a[j--]=a[j-1];
		}
        a[j]=x;
    }
    showarr(a,10);
    cout<<"\nend\n";
}

void selection_sort(int a[])
{   cout<<"\nSelection sort\n\n";
    int n=10,i;
	for (i=1;i<n;i++)
	{	int k=0;
  		for (int j=1;j<=n-i;j++)
			if (a[j]>a[k])
				k=j;
        showarr(a,10);
        getche();
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
{   cout<<"\nBUBBLE SORT\n";
    int n=10;
	for(int i=1;i<9;i++)
	{	for(int j=0;j<10-i;j++)
		{	if(a[j]>a[j+1])
			{   showarr(a,10);
                getche();
                swap(a[j],a[j+1]);
            }
		}
	}
	showarr(a,10);
    cout<<"\nend\n";
}

void merge_sort(int a[],int b[])
{   cout<<"\nMerge sort\n\n";
    int n=10,c[20],j=0,i,p,m=0;
	for(i=1;i<9;i++)
	{	for(int j=0;j<10-i;j++)
		{	if(a[j]>a[j+1])
			{   swap(a[j],a[j+1]);
            }
		}
	}
    for(i=0;i<10;i++)
    {   c[i]=a[i];
    }
    m=9;
    //cout<<"\nGETCHE";
    getche();
    for(i=0;i<10;i++)
    {   c[m+1]=b[i];
        for(j=m;j>=0;j--)
        {    if(c[j]>=c[m+1])
                 swap(c[j],c[m+1]);
        }
        m++;
    }
    showarr(c,20);
}






