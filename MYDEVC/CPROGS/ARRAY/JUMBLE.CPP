#include <iostream.h>
#include <conio.h>

void main()
{   int arr[4] = { 4,5,7,1 };
    int shoarr(int [],int);
    int fact(int);
    int i=0, p = 0;
    while ( i < fact(4))
    {   int j = 0;
        while(j<4)
        {   p = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = p;
            j++;
            shoarr(arr,4);
            i++;
            getche();
        }
    }
    getche();
}

int shoarr(int a[],int n)
{   for(int x=0; x<n; x++) cout<<a[x]<<"\t";
    cout<<endl;
}

int fact(int f)
{   int fct = 1;
    while(f) fct *= f--;
    return fct;
}
