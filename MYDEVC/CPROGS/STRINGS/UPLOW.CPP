#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
void main()
{
    char ch[50], pre = '\0';
    cout<<"Enter a word : "; gets(ch);
    for(int i = 0; i < strlen(ch); i++)
    {
        if(ch[i] == pre+1)
            cout << pre <<"\t"<< ch[i]<<endl;
        pre = ch[i];
    }

    cout<<endl;
    system("PAUSE");
}
