#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class fibo
{   private:
        int a;
        int b;
        int c;
    public:
        fibo();
        void increment();
        void show();
};

fibo::fibo()
{   a = 0;
    b = 1;
    c = a + b;
}
void fibo::increment()
{   a = b;
    b = c;
    c = a + b;
}
void fibo::show()
{   cout<<c<<"\t"; }

void main()
{   fibo number;
    for(int i = 0; i < 15; i++)
    {   number.show();
        number.increment();
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
