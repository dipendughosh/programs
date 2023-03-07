#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
/*struct case1
    { int a;
    }test1;
struct case2
    { int a;
    }test2;*/

void main()
{   //test1.a == 12; test2.a = 12;
    int test1[2]={2,3}, test2[2]={2,3};
    if(test1 == test2) cout<<"Good";
        else cout<<"\nBad"<<endl;
     getche();
}
