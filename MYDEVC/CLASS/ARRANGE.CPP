#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
class number
{   int num;
    public:
        void getnum(); void shownum();
};
int main()
{   number no[4];
    for ( int i = 0; i<4; i++ ) no[i].getnum();
    for ( int i = 3; i>=0; i-- ) no[i].shownum();
    getche();
    return 0;
}
void number::getnum()
{   cout<<"Enter a number : "; cin>>num; }
void number::shownum()
{   cout<<num<<endl; }

