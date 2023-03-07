/*/3
//Binary search & Linear search (done)*/
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	int cho;
	char y;
	void binsearch();
	void linsearch();
	do
	{       clrscr();
		cout<<"\a      MENU";
		cout<<"\n1.Binary Search";
		cout<<"\n2.Linear Search";
		cout<<"\n3.Exit";
		cout<<"\nEnter choice :";
		cin>>cho;
		switch(cho)
		{	case 1:
				binsearch();
			break;
			case 2:
				linsearch();
			break;
			case 3:
			break;
			default:
				cout<<"\nWrong Choice:";
			break;
		}
		cout<<"\nDo you want to continue:::->";
		cin>>y;
	}
	while(y=='y' || y=='Y');
	cout<<"\nPRESS ANY KEY TO CONTINUE ............"<<(char)7;
	getche();
}
void binsearch()
{       int arr[10],num,high=10,c=0,i,j,mid=0,temp,low=0;
	cout<<"Enter array :\n";
	for(i=0;i<10;i++)
	{	cin>>arr[i];
	}
	cout<<"Enter number to search :";
	cin>>num;
	for(i=0;i<9;i++)
	{	for(j=i+1;j<10;j++)
		{	if(arr[i]>arr[j])
			{	temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	do
	{	mid=(low+high)/2;
		if(arr[mid]==num)
		{	cout<<"\n"<<num<<" is in "<<mid+1;
			c=1;
			break;
		}
		if(arr[mid]>num)
		{	high=mid-1;
			c=0;
		}
		else if(arr[mid]<num)
		{	low=mid+1;
			c=0;
		}
	}
	while(low!=high);
	if(c==0)
	{	cout<<"\nNumber is not present in array";
	}
}
void linsearch()
{       int arr[10],num,i,j,temp;
	cout<<"Enter array :\n";
	for(i=0;i<10;i++)
	{	cin>>arr[i];
	}
	cout<<"Enter number to search :";
	cin>>num;
	for(i=0;i<9;i++)
	{	for(j=i+1;j<10;j++)
		{	if(arr[i]>arr[j])
			{	temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	for(i=0;i<10;i++)
	{	if(num==arr[i])
		{	cout<<arr[i]<<" is in "<<i+1;
			break;
		}
	}
}