#include <iostream.h>
#include <conio.h>

int main()
{   int index=39,*ptr1,*ptr2;
    ptr1=&index;
    ptr2=ptr1;
    cout<<"Index= "<<index;
    cout<<"\n*ptr1= "<<*ptr1;
    cout<<"\n*ptr2= "<<*ptr2;
    *ptr1=13;
    cout<<"\n\nIndex= "<<index;
    cout<<"\n*ptr1= "<<*ptr1;
    cout<<"\n*ptr2= "<<*ptr2;
    getche();
    return 0;
}
