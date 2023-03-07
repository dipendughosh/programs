#include <iostream.h>
#include <stdlib.h>
//#include <conio.h>
#include <stdio.h>  //gets() n puts()
#include <string.h> //strlen()

int main()
{
    char b[100];
    int length,i;
    cout<<"enter your name  ";
    gets(b);
    length = strlen(b);
    cout<<"the name is ";
    puts(b);
    cout<<"the length is "<<length;
    for(i=0;i<length;i++)
    {
        cout<<"\n"<<b[i];
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
