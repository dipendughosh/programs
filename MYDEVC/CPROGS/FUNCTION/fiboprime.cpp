#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int fibo(int), n = 1, isfive = 0;
    long fact(int), total = 0;
    do
    {   if(fibo(n))
        {   total += fact(n);
            isfive++;
            cout<<"\nfibo = "<<n<<" : fact = "<<fact(n)<<" --> "<<isfive;
        }
        n++;
    } while(isfive < 5);
    cout<<"\nSum of first 5 fibonacci numbers is :\n"<<total;
    cout<<endl;
    system("PAUSE");
    return 0;
}

int fibo(int x)
{   int a,b,c;
    a = 0; b = 1;
    while(a <= x)
    {   a = a + b;
       // cout<<a<<"\t";
        if (a == x) return 1;
        c = b; b = a; a = c;
    }
    return 0;
}

long fact(int y)
{   int f = 1;
    while(y) f *= y--;
//    cout<<f<<"\n";
    return f;
}

