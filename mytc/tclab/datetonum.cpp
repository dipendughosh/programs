#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int a = 65, i = 0;
    do
    {   for(int j = 0; j < i; j++)
            cout<< (char)a++;
        i++;
        cout<<endl;
    }
    while( a <= 91);
    cout<<endl;
    system("PAUSE");
    return 0;
}
