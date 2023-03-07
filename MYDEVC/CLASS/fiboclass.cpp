#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class fibo
{   private:
    int f0,f1,fib;
    public:
    fibo();
    void increment();
    void display();
};
fibo::fibo()
{   f0 = 0;
    f1 = 1;
    fib = f0 + f1;
}
void fibo::increment()
{   f0 = f1;
    f1 = fib;
    fib = f0 + f1;
}
void fibo::display()
{   cout<<f1<<"\t";
}

int main()
{   fibo number;
    cout<<"\nFirst 10 numbers of Fibonacci Series are :\n\n";
    for(int i = 0; i < 10; i++)
    {    number.display();
        number.increment();
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
