// Pascal's Triangle ( Combination formula )
#include <iostream.h>
#include <stdlib.h>          // for system("PAUSE")
#include <conio.h>
#include <iomanip.h>        // for setw()

int main()
{   long comb(int,int);
    int r,i,j;
    cout<<"\nEnter no. of rows : "; cin>>r;
    cout<<endl;
    for(i = 0; i < r; i++)
    {   for(j = 1; j < r-i; j++)
            cout<<setw(2)<<" ";
        for(j = 0; j <= i; j++)
            cout<<setw(4)<<comb(i,j);
        cout<<endl;
    }
    cout<<"\n\n This is a Pascal's Triangle with "<<r<<" rows\n";
    system("PAUSE");
    return 0;
}

long comb(int n,int k)
{   long c = 1;
    if(n < 0 || k < 0 || k > n) return 0;
    for(int x = 1; x <= k; x++,n--) c = c * n / x;
    return c;
}

