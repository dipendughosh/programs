#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int sort(int[],int);
	int input(int[],int);
	void output(int[],int);
	int arr[50],size,i;
	cout<<"Input size of the array =====>  ";
	cin>>size;
	input(arr,size);
	sort(arr,size);
	output(arr,size);
	getche();
}
int input(int a[],int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		cout<<"enter a number    ";
		cin>>a[i];
	}
	return 0;
}
int sort(int a[],int s)
{
	int i,j,temp,small,k;
	for(i=0;i<s;i++)
	{
		//small = a[i];
		k = i+1;
		for(j=k;j<s;j++)
		{
			if(a[j]<a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;

			}
		}
	}
	return 0;
}

void output(int a[], int s)
{
	int i;
	for(i=0;i<s;i++)
		cout<<"\t"<<a[i];
}



