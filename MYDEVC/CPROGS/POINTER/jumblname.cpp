#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{   char *n[]={"kapil","sunil","sachin",
              "sourav","dravid","anil"};
    char* p;
    p=n[0];
    for(int i=0;i<6;i++)
    {   cout<<*p<<"\n";
        p++;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
