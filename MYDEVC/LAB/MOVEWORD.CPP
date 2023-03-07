#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char str[] = "WORLD";
    int len = strlen(str), row = 12, col = 0;
    while(col < 79)
    {
        for(int i = 0; i < len; i++)
        {   gotoxy(row,col++);
            cout<<str[i];
        }
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
