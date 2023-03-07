#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   char* names[] = {"Sachin","Sourav",
                     "Dravid","Laxman"};
    char* name[];
    for(int i=0;i<4;i++)
    {   *name=names[i];
        while(*name)  cout<<*name++;
        /*for(int j=0;j<4;j++)// cout<<names[i];
            cout<<names[j];   */
       cout<<endl;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
