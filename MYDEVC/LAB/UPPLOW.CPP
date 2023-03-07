#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main()
{
    char string[80];
    gets(string);
    for(int i = 0; i<strlen(string); i++)
    {   if(islower(string[i]))
            cout<<(char)toupper(string[i]);
        else
            cout<<(char)tolower(string[i]);
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
