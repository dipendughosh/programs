// the frigtening pointers!!!
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int main()
{   void strplay(char*);
    char arr[]="the then theatre";
    strplay(arr);
    getche();
    return 0;
}

void strplay(char* ww)
{   cout<<endl;
    while (*ww) cout<<*ww++;
}


