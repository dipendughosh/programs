#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int a = 4,b = 5,c = 6;
    int* pa,pb;
    cout<<a<<"\t"<<&a<<endl;
    cout<<b<<"\t"<<&b<<endl;
    cout<<c<<"\t"<<&c;
    pa = &a;
    cout<<"\n"<<pa<<"\t"<<*pa;
    *pa += 12;
    cout<<"\n"<<pa<<"\t"<<*pa;
    pa -= 8;
    cout<<"\n"<<pa<<"\t"<<*pa;
    cout<<endl;
    system("PAUSE");
    return 0;
}
