#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class count
{   static int n;
    public:
        count(){ n++; )
        int showcount()
        {   return n; }
        void getcount()
        {   n++; }
};
int main()
{   count cc,dd,ee;
    cout<<cc.showcount();
    //cc.getcount();
    cout<<dd.showcount();
    cout<<endl;
    system("PAUSE");
    return 0;
}
