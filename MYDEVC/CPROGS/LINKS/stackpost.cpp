#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
void main()
{
    char stak[50];
    int i = 0;
    gets(stak);
    while(stak[i]) cout<<stak[i++]<<"\n";
    cout<<endl;
    system("PAUSE");
}
