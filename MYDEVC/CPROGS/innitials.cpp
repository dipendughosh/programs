#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
int main()
{   int p,x;
    char a[500];
    gets(a);
    p=strlen(a);
    x=p-1;
    for(int i=p-1;a[i]!=' ';i--)
        x--;
    cout<<a[0]<<".";
    for(int j=1;j<=x-1;j++)
        if(a[j]==' ')
            cout<<a[j+1]<<".";
    for(int k=x+1;a[k]!='\0';k++)
        cout<<a[k];
    cout<<".";
    cout<<endl;
    system("PAUSE");
    return 0;
}
