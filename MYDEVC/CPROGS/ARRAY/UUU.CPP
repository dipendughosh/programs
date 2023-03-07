#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int a = 6;
    cout<<"\n1 "<<&a<<"\t"<<a;
    {   int a = 8;
        cout<<"\n2 "<<&a<<"\t"<<a;
        {   int a = 7;
            cout<<"\n3 "<<&a<<"\t"<<a;
        }
        cout<<"\n4 "<<&a<<"\t"<<a;
     }
    cout<<"\n5 "<<&a<<"\t"<<a;
    cout<<endl;
    system("PAUSE");
    return 0;
}


