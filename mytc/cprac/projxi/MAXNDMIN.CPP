#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int arr[100],i;
	void output(int[100]);
	for(i = 0;i<10;i++)
	{
		cout<<"\nenter a number\n ";
		cin>>arr[i];
	}
	output(arr);
	getche();
}
void output(int arr[])
{
	int i=0;
	float avg=0,max = arr[i],min = arr[i];;
	clrscr();
	cout<<"\nThe array is ::::\n";
	cout<<arr[i];
	for(i = 1;i<10;i++)
	{
		cout<<" "<<arr[i];
		if(arr[i]>max)
			max = arr[i];
		if(arr[i]<min)
			min = arr[i];
	}
	avg = (max+min)/2;
	cout<<"\nThe LARGEST number of the above  array is "<<max;
	cout<<"\nTHE smallest NUMBER OF THE ABOVE ARRAY IS "<<min;
	cout<<"\nThe avarage of "<<max<<" and "<<min<<" is "<<avg;
}




