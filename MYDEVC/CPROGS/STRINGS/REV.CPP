#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

int main()
{   int len;
    char s[21];
    gets(s);
    len=strlen(s);
    cout<<"\n";
    puts(s);
    cout<<"\n\n\n";
    for(int i=0;i<len;i++) cout<<s[i];
    cout<<endl;
    system("PAUSE");
    return 0;
}
