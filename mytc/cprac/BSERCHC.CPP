#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	void ascend(int[]);
	int arr[] = { 3,6,7,2,9,32,34,0,-4,76};
	int top=0,i,bot=10,num,half,flag = 0;
 /*	for(;i<m;i++)
	{
		cout<<"\n enter a number ";
		cin>>arr[i];
	}*/
	ascend(arr);
	for(i=0;i<bot;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"enter a number to be checked ";
	cin>>num;

	while(top!=bot)
	{
		half = (top+bot)/2;
		if(arr[half]==num)
		{
			flag = 1;
			cout<<"the number "<<num<<" is present in the array in position number "<<(half+1);
			break;
		}
		if(arr[half]<num) top = half+1;
		if(arr[half]>num) bot = half-1;
	}
	if(flag == 0)
		cout<<"\nThe number is not present";
	getche();
}

void ascend(int a[])
{
	int temp,s;
	for(int i=0;i<10;i++)
	{
		s = a[i];
		for(int j =i+1;j<10;j++)
		{
			if(a[j]<s)
			{
				temp = s;
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
