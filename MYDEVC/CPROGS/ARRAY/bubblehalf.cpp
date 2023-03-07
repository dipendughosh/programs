/*** DOUBLE BUBBLE ***/

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define size 20
void showarr(int a[], int s, int e)
{
    for (int i = s;i < e; i++)
		cout << a[i] << "  ";
	cout << endl;
}
void swap(int &x, int &y)
{
    int temp = x;
	x = y;
	y = temp;
}

int main()
{
    void bubbleUp(int[], int, int);
    void bubbleDn(int[], int, int);
    int arr[size];
    //clrscr();
    cout<<"Input numbers for the Array :\n";
    for(int i = 0; i < size; i++)
    {   cout << "Index " << i << " : ";
        cin >> arr[i];
    }
    cout << "\nThe Array is :\n";
    showarr(arr, 0, size);
    int mid = size/2;
    bubbleUp(arr, 0, mid);
    cout << "\n\tAfter sorting (Asc.) 1st. half  :\n";
    cout << "\t\t"; showarr(arr, 0, mid);
    bubbleDn(arr, mid, size);
    cout << "\n\tAfter sorting (Desc.) 2nd. half :\n";
    cout << "\t\t"; showarr(arr, mid, size);
    cout<<endl;
    cout << "\n\nNow the whole resultant array :\n";
    showarr(arr, 0, size);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void bubbleUp(int a[], int start, int end)
{
	for(int i = start+1; i < end-1; i++)
		for(int j = start; j < end-i; j++)
			if(a[j] > a[j+1]) swap(a[j], a[j+1]);
}

void bubbleDn(int a[], int start, int end)
{
	for(int i = start+1; i < end; i++)
		for(int j = start; j < end-1; j++)
		  if(a[j] < a[j+1]) swap(a[j], a[j+1]);
}

