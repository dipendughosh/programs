#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>

class indexedarray
{	int arr[100];
	public:
	indexedarray();
	void fillarr();
	void sortarr();
	int binarysearch(int);
};

indexedarray::indexedarray()
{	int i;
	for(i=0;i<100;i++)
		arr[i]=0;
}

void indexedarray::fillarr()
{	int i;
	cout<<"\nFill array\n";
	for(i=0;i<10;i++)
		cin>>arr[i];
}

void indexedarray::sortarr()
{	int i,k,j,temp;
	for (i=1;i<10;i++)
	{	k=0;
		for (j=1;j<=10-i;j++)
			if (arr[j]>arr[k])
				k=j;
		temp=arr[k];
		arr[k]=arr[10-i];
		arr[10-i]=temp;
	}
}

int indexedarray::binarysearch(int n)
{	int high=10,c=0,i,j,mid,low=0;
	do
	{	mid=(high+low)/2;
		if(arr[mid]==n)
		{	c=1;
			break;
		}
		else
		{	if(arr[mid]>n)
				high=mid-1;
			else
				low=mid+1;
		}
	}
	while(c!=1 || high==low);
	return c;
}
void main()
{	clrscr();
	int x,c;
	indexedarray a;
	a.fillarr();
	a.sortarr();
	cout<<"\nEnter code to search";
	cin>>x;
	c=a.binarysearch(x);
	if(c==1)
		cout<<"\nPresent";
	else
		cout<<"\nAbsent";

	getche();
}
