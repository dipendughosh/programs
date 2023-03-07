//incomplete
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#define l 10
void main()
{	clrscr();
	//int arr[10];
	int i,j,k,ch,count=0;
	void shift(int [],int,int );
	void display(int [],int);
	int arr[l]={10,20,30,30,35,40,50,50,60,70};
	//cout<<" enter elements of array in ascending order ";
	for(i=0;i<l;i++)
		cout<<arr[i]<<"\t";
	for(i=0;i<l;i++)
	{	for(j=i+1;j< l-1;j++)
		{   ch=0;
				while(arr[i]==arr[j])
				{	for(k=j-1;k<9;k++)
					{
						if(arr[i]==arr[k])
						{	ch++;   count++;   }
						if(ch>=1)
							shift(arr,k,ch);
					}
				 }
		}

	}
	display(arr,count);
	getche();
}
void shift(int array[],int a,int b)
{	for(int i=a;i<l-b;i++)
		array[i]=array[i+1];
}
void display(int array[],int last)
{
	for(int i=0;i<(l-last);i++)
		cout<<array[i]<<"\t";
}




