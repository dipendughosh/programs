// 1!+4!+5! = 145 : How many of those between 1 - 100000
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

long main()
{   long i,n,num,f;
    long fact(long);
    for ( i = 1; i < 100000; i++ )
    {   n = i; f = 0;
        if (n > 10)
        {   while( n )
            {   num = n % 10;
                f += fact(num);
                n /= 10;
            }
        }
        else f = fact(n);
        if (i == f) cout<<"\ngot one "<<i<<endl;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}

long fact(long number)
{   long fn = 1;
    while(number) fn *= number--;
    return fn;
}
