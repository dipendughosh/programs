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
	void binsearch();
	void linsearch();
	cout<<"\tMENU";
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
	cout<<"\nPRESS ANY KEY TO CONTINUE ............"<<(char)7;
	getche();
}
void binsearch()
{       int arr[5],num,high=5,c=0,i,j,mid,temp,low=0,pos[5];
	cout<<"Enter array :\n";
	for(i=0;i<5;i++)
	{	cin>>arr[i];
		pos[i]=i+1;
	}
	cout<<"Enter number to search :";
	cin>>num;
	for(i=0;i<4;i++)
	{	for(j=i+1;j<5;j++)
		{	if(arr[i]>arr[j])
			{	temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
				temp=pos[j];
				pos[j]=pos[i];
				pos[i]=temp;
			}
		}
	}
	do
	{	mid=high/2;
		if(arr[mid]==num)
		{	cout<<"\n"<<num<<" is in "<<pos[mid];
			c=1;
		}
		else
		{	if(arr[mid]>=num)
				high=mid;
			else
				low=mid;
		}
	}
	while(c!=1);
}
void linsearch()
{       int arr[5],num,i,j,temp,pos[5];
	cout<<"Enter array :\n";
	for(i=0;i<5;i++)
	{	cin>>arr[i];
		pos[i]=i+1;
	}
	cout<<"Enter number to search :";
	cin>>num;
	for(i=0;i<4;i++)
	{	for(j=i+1;j<5;j++)
		{	if(arr[i]>arr[j])
			{	temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
				temp=pos[j];
				pos[j]=pos[i];
				pos[i]=temp;
			}
		}
	}
	for(i=0;i<5;i++)
	{	if(num==arr[i])
		{	cout<<arr[i]<<" is in "<<pos[i];
			break;
		}
	}
}