#include<iostream.h>
#include<conio.h>
void main()
{	int arr[5]={1,2,3,4,5};
	void print(int *);
	print (arr);
	getche();
 }
void print (int  *arr)
 {	cout<<" printing ";
	for(int i=0;i<5;i++)
		cout<<*(arr+i)<<"\t";
 }
