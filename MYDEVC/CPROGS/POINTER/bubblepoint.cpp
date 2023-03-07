#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define N 10
int main()
{   int arr[N]={35,24,85,14,2,96,5,47,22,9};
    void bsort(int*, int);
    bsort(arr,N);
    for (int i=0; i<N; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    system("PAUSE");
    return 0;
}

void bsort(int* ptr, int n)
{    void swap(int*, int*);
     for(int i=0; i<n-1; i++)
         for(int j=i+1; j<n; j++)
             swap(ptr+i, ptr+j);
}
void swap(int* x, int* y)
{    if(*x > *y)
     {     int temp = *x;
          *x = *y;
          *y = temp;
     }
}
