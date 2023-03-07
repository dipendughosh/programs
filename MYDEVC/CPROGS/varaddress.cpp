#include <iostream.h>
#include <conio.h>

void main()
{   int a=12004, b=40012;
    int* ptra; int* ptrb;
    ptra = &a; ptrb = &b;
    cout<<"a = "<<a<<" ---> ";
    cout<<"*ptra = "<<*ptra<<endl;
    cout<<"b = "<<b<<" ---> ";
    cout<<"*ptrb = "<<*ptrb<<endl;
    getche();
}
