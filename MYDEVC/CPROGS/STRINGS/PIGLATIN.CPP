//wrong
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{   char ch,s[30];
    int len,sp,i=0;
    cout<<"\nEnter a sentence : ";  gets(s);
    len = strlen(s);
    while(i<22)
    {   if(s[i]==' ') i++;
        ch=s[i++];
        while(s[i]!=' ')
        {   cout<<s[i++]<<"\t"<<i<<"\n";
            getche();
        }
        //cout<<ch<<'a ';
    }
    //cout<<ch<<"a";
    cout<<endl;
    system("PAUSE");
    return 0;
}
