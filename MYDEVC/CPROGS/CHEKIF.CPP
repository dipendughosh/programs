#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int x = 4, y = 1, c;
    char ch;
    ch = 'A';
    c = (int)ch;
    if(x == 0)
    {   if(y == 0)
            cout<<"BOTH";
         else
           cout<<"NOT";
    }
    cout<<ch + 32;
    cout<<"\n"<<(char)(c+32);
    cout<<endl;
    system("PAUSE");
    return 0;
}
