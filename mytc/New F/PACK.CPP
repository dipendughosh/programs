#include<iostream.h>
#include<conio.h>
define SIZE 15
void main()
{
	int arr[SIZE] = { 2,56,3,2,4,5,3,3,4,2,10,2,32,45,56};
	for(int i = 0; i < 15; i++)
	{   if (found(arr,arr[i]))
		{	packar(arr,i);
			SIZE--;
			showarr(arr,SIZE);
		}
	}
   // showarr(arr,SIZE);
}

void showarr(int a[],int S)
{
	for(int x = 0; x < S; x++) cout<<a[x];
}
bool found(int a[],const int S,int n)
{
	for(int x = 0; x < S; x++)
		if(a[x] == n)


