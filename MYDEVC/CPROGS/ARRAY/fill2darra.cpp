#include <iostream.h>
#include <conio.h>
const int M = 10;
void main()
{   int arr[M][M];
    int n = 5;
    void fill(int[M][M],int);
    void shoarr(int[M][M],int);
    fill(arr,n);
    shoarr(arr,n);
    getche();
}

void fill(int a[M][M],int p)
{   int z=1;
    for(int x=0;x<p;x++)
    {   for(int y=0;y<p;y++)
            a[x][y] = z++;
    }
}

void shoarr(int a[M][M],int p)
{   for(int x=0;x<p;x++)
    {   for(int y=0;y<p;y++)
            cout<<a[x][y]<<"\t";
        cout<<"\n\n";
    }
}
