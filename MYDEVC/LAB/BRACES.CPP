#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int i = 11;
    cout<<"\nFirst i = "<<i;
    {   int i = 22;
        int p = 2;
        cout<<"\nSecond i = "<<i;
        {   int i = 33;
            cout<<"\nThird i = "<<i;
            cout<<"\np = "<<p;
        }
        cout<<"\nFourth i = "<<i;
        cout<<"\np = "<<p;
    }
    cout<<"\nFifth i = "<<i;
    cout<<endl;
    system("PAUSE");
    return 0;
}
