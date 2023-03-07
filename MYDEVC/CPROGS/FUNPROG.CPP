#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   char n[]="nikhil";
    int len=6,row=0,col=len-1,z;
    void wait();
    while (col<=40)
    {
        //for (int y=0;y<40-col-len;y++)  cout<<' ';
        for (z=0;z<len;z++)
        {   gotoxy(row,col++);
            cout<<n[z];
            wait();
        }

    }
    cout<<endl;
    system("PAUSE");
    return 0;
}

void wait()
{   for (int x=0;x<5000;x++) {}
}
