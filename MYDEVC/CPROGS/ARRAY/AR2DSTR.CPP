#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main()
{   char arr[2][20];
    int i,j,len,x=0;
    cout<<"ENTER THE STRING ";
    cin.getline(arr [0],20);
    len=strlen(arr[0]);
    for(j=len-1,x=0;j>=0;j--,x++)
        arr[1][x]=arr[0][j];
    //getche();
    for (i = 0; i < 2;i++)
    {    for (j = 0;j <len;j++)
                cout<<arr[i][j];
         cout<<"\n";
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
