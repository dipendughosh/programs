#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    boolean prime(int),palin(int);
    for (int i = 100; i < 1000; i++)
    {
        if(prime(i))
            if(palin(i))
                cout<<"\nPrime-Palindrome "<<i;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}

boolean prime(int x)
{
    for(int i = 2; i <= x/2; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}


