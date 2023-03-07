//Binary search
#include<conio.h>
#include<string.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
int main()
{
	//clrscr();
	int arr[33];
	void sort(int[]);
	void prn(int[]);
	for(int i=0;i<33;i++)
	{
		cout<<"\nEnter data...--->";cin>>arr[i];
	}
	//clrscr();
	prn(arr);
	sort(arr);
	prn(arr);
	int high=33,low=0,c=0,ser;
	int mid;
	cout<<"\nEnter search term....";cin>>ser;
	do
	{
		mid=(high+low)/2;
		if(ser==arr[mid])
		{
			cout<<"\nFound  \nPosition is ..."<<mid+1;
			c=1;
			break;
		}
		if(ser>=arr[mid])
		{
			low=mid;
		}
		else
		{
			high=mid;
		}
	}
	while(low<high-1);
	if(c==0)
	{
		cout<<"\nSorry number is absent.........\n";
	}
	getche();
	return 0;
}
void sort(int a[])
{
	int temp;
	for(int i=0;i<32;i++)
	{
		for(int j=i+1;j<33;j++)
		{
			if(a[i]>=a[j])
			{
				//swaping the values
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
}
void prn(int x[])
{
	cout<<"\n";
	for(int i=0;i<33;i++)
		cout<<x[i]<<"\t";
	cout<<endl;
}