/*** BINARY SEARCH ***/

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    //clrscr();
	void selesort(int[], int);
 	int arr[] = { 3,6,7,2,9,32,34,0,-4,76};
	int top = 0, i = 0, size, bot, num, half, flag = 0;
    cout << "Enter size of array : "; cin >> size;

    cout << "\nFill the array please..." << endl;
 	for(; i < size; i++) {   cout<<"Number "; cin>>arr[i]; }

    cout << "\nThe array is -->" << endl;
    for(i = 0; i < size; i++) cout<<arr[i]<<"   ";

    // Sorting the array (Ascending)
	selesort(arr, size);
    cout << "\nAfter sorting, the array is -->" << endl;
    for(i = 0; i < size; i++) cout<<arr[i]<<"   ";

  	cout << "\nEnter a number to search : "; cin>>num;

    // The Search...

    bot = size;
	while(top <= bot)
	{
		half = (top+bot) / 2;
		if(arr[half] == num)
		{
			flag = 1;
			cout<<"\nThe number "<<num<<" is present"
                << " in position number "<<(half+1);
			break;
		}
		if(arr[half] < num) top = half+1;
		if(arr[half] > num) bot = half-1;
	}
	if(flag == 0)
		cout<<"\nThe number is not present";
    cout<<endl;
    system("PAUSE");
    return 0;
}

void selesort(int a[], int sz)
{
    void swap(int&, int&);
	for(int i = 1; i < sz; i++)
	{	int k = 0;
  		for(int j = 1; j <= sz-i; j++)
			if(a[j] > a[k]) k = j;
		swap(a[k], a[sz-i]);
	}
}

void swap(int &x,int &y)
{	int temp = x;
	x = y;
	y = temp;
}


