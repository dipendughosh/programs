#include <iostream.h>
#include <conio.h>

void main()
{   int a = 4;
    int* ptr1, *ptr2;
    ptr1 = &a;
    cout<<"a = "<<a<<"\t&a = "<<&a<<"\t*ptr1 = "<<*ptr1;
    ptr2 = ptr1 - 2;
    cout<<"\nAfter increment, &a = "<<&a<<"\t*ptr2 = "<<*ptr2;
    getche();
}
