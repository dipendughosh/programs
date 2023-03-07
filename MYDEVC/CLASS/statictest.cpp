#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class abc
{   private:
        static int count;
    public:
        abc()
        {   ++count;
        }
        int count_ch()
        {   return count;
        }
};

int abc::count=0;

int main()
{   abc x1,x2;
    cout<<x1.count<<"   ";
    {   abc q,w,e,r;
        cout<<x1.count<<"   ";
    }
    cout<<x1.count<<"   ";
    abc t;
    cout<<x1.count<<"   ";
    cout<<endl;
    system("PAUSE");
    return 0;
}
