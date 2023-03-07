#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int arr[5],num,i,j,temp,pos[5];
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
	getch();
}
