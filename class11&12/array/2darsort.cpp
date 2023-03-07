#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

void main()
{   clrscr();
    int a[10],i,j,temp,n,p;
    cout<<"\nEnter size of array : ";
    cin>>n;
    void display(int[],int);
    if(n>0)
    {   for(i=0;i<n;i++)
	    a[i]=i+1;
	display(a,n);
	for(i=0;i<n-1;i++)
	{   temp=a[0];
	    for(j=0;j<n-1;j++)
	    {   a[j]=a[j+1];
	    }
	    a[j]=temp;
	    display(a,n);
	}
    }
    else
    {   p=n;
	n*=(-1);
	for(i=0;i<n;i++)
	   a[i]=p++;
	display(a,n);
	for(i=0;i<n-1;i++)
	{   temp=a[0];
	    for(j=0;j<n-1;j++)
	    {   a[j]=a[j+1];
	    }
	    a[j]=temp;
	    display(a,n);
	}
    }
    getche();
    //cout<<endl;
    //system("PAUSE");
    //return 0;
}
void display(int arr[],int m)
{   int i;
    for(i=0;i<m;i++)
        cout<<arr[i]<<"\t";
    cout<<"\n";
}
