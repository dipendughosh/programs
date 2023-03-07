#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

void main()
{   long fact(int,int),p;
    int	 n,k;
    do
    { clrscr();
      cout<<"Enter greater number : "; cin>>n;
      cout<<"Enter smaller number : "; cin>>k;
    } while (n<=k);
    p = fact(n,0)/fact(n,k);
    cout<<"Permutation "<<p;
    getche();
}

long fact(int x,int y)
{   int f=1;
    int z=x-y;
    for (int i=z; i>0; i--) f*=i;
    return(f);
}

