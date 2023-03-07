#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{   int* big(int, int);        // Returns pointer, receives reference
    int a = 4,b = 8,*c;        // *c to hold the return value
    c = big(a,b);
    cout<<"\nBigger is : " << *c;
    cout<<endl;
    system("PAUSE");
    return 0;
}
int* big(int x, int y)
{   if( x > y ) return (&x);
    else return (&y );
}
