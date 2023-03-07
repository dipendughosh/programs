#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int main()
{   char word[80];
    do
    {   cin>>word;
        if (*word) cout<< word << " ";
    }
    while(*word);
    getche();
    return 0;
}
