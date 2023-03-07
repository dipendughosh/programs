#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class thisis
{   int x;
    public:
        void showthis()
        {   cout<<"\nThe address is : " << this; }
};
int main()
{   thisis obj1, obj2, obj3;
    obj1.showthis();
    obj2.showthis();
    obj3.showthis();
    cout<<endl;
    system("PAUSE");
    return 0;
}
