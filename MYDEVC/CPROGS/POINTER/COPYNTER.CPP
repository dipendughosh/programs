#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int var1 = 22; int var2 = 20;
    int* ptr1; int* ptr2; // declaration of pointers
    ptr1 = &var1; ptr2 = &var2;
    cout<<"\nvar1 = "<<var1<<"\tptr1 = "<<ptr1<<"\t*ptr1 = "<<*ptr1<<endl;
    cout<<"\nvar2 = "<<var2<<"\tptr2 = "<<ptr2<<"\t*ptr2 = "<<*ptr2<<endl;
    ptr1++; ptr2++;
    cout<<"\nAfter ++ ...\n";
    cout<<"\nvar1 = "<<var1<<"\tptr1 = "<<ptr1<<"\t*ptr1 = "<<*ptr1<<endl;
    cout<<"\nvar2 = "<<var2<<"\tptr2 = "<<ptr2<<"\t*ptr2 = "<<*ptr2<<endl;
    cout<<"\nAddress of var1 : "<<&var1;
    cout<<"\nAddress of ptr1 : "<<&ptr1;
    cout<<endl;
    system("PAUSE");
    return 0;
}
