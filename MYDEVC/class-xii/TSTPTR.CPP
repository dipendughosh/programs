#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int a = 44;//{44,1,54,7};
    int *ptr1 , *ptr2;
    ptr1 = &a;
    /*for(int i = 0; i < 4; i++)
        cout<<*(ptr1+i)<<"\t";*/
    ptr2 = new int;
    ptr2 = &ptr1;

    *ptr2 = *ptr1;
    cout<<ptr1<<"\t"<<ptr2;

    cout<<endl;
    system("PAUSE");
    return 0;
}
