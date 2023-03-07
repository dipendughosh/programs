// string prog
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

int main()
{   char s[51],w[51];
    cout<<"Enter main string : "; gets(s);
    cout<<"\nEnter sub-string : "; gets(w);
    int len1,len2,p=0,c=0;
    len1=strlen(s);
    len2=strlen(w);
    for(int i=0;i<len1;i++)
    {
        if(s[i]==w[0])
        {   c=0;p=0;
            for(int a=i;a<(i+len2);a++)
            {   if(s[a]==w[p++])  c++;
            }
            if(c==len2)
                for(int q=i;q<(i+len2);q++) s[q]='x';
        }
    }
    cout<<"\n";
    puts(s);
    cout<<endl;
    system("PAUSE");
    return 0;
}
