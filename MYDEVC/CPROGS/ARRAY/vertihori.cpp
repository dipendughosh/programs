// crossed output of array
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip.h>

#define MAX 50

int main()
{
    int arr1[MAX],arr2[MAX];
    int joinarr[MAX][MAX];
    void swap(int&, int&);
    void shoarr(int[], int);
    int shoarr(int[MAX][MAX], int);
    int search(int[], int, int);
    int i,j,n1,n2,jrow,jcol,newrow,index,size;

    cout<<"Enter size of array : "; cin>>size;
    cout<<"Enter data for the array with non-zero unique numbers ===>\n";
    for(i = 0; i < size; i++) cin>>arr1[i];
    // Here a check may be written for duplicate input
    for(i = 0; i < size; i++) arr2[i] = arr1[i]; // copying...
    for(i = 0; i < size-1; i++)          // sorting second array
        for(j = i+1; j < size; j++)
            if(arr2[i] > arr2[j]) swap(arr2[i],arr2[j]);

    for(i = 0; i < MAX; i++)        // initializing 2D array with 0
        for(j = 0; j < MAX; j++)
            joinarr[i][j] = 0;

    cout<<"Original array : ";
    shoarr(arr1,size);
    cout<<"\nSorted form    : ";
    shoarr(arr2,size);
    cout<<endl;

    jrow = size - 1;
    jcol = 0;
    for(i = 0; i < size; i++)
    {   n1 = arr1[i];
        index = search(arr2,size,n1);
        newrow = jrow - index;
        for(j = 0; j < size; j++)
            joinarr[newrow++][jcol] = arr2[j];
        jcol++;
    }

    cout<<"\nCrossed Output : \n";
    shoarr(joinarr,(size*2)-1);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void swap(int& x, int& y)
{   int temp = x;
    x = y;
    y = temp;
}

void shoarr(int a[], int l)
{   for(int p = 0; p < l; p++)
        cout<<a[p]<<"\t";
}

void shoarr(int a[MAX][MAX], int l)
{   for(int p = 0; p < l; p++)
    {   for(int q = 0; q < l; q++)
        {   if(a[p][q] == 0) cout<<"   "<<"\t";
            else cout<<setw(3)<<a[p][q]<<"\t";
        }
        cout<<endl;
    }
}

int search(int a[], int s, int n)
{   for(int x = 0; x < s; x++)
        if(a[x] == n) return x;
}

