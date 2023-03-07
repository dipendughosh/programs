#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   char str[30],revstr[30];
    int i,j=0,p=1,l;
    cout<<"Enter a string : "; cin.getline(str,30);
    l = strlen(str);
    for( i = l-1; i >= 0; i-- )
    {   if(str[i] == ' ') continue;
        revstr[j++] = str[i];
    }
    revstr[j] = '\0';
    cout<<revstr<<endl;
    for( i = strlen(revstr)-1,j=0; i >= 0; i--,j++ )
        if(revstr[i] != revstr[j]) p = 0;
    if(p==0) cout<<"\nNot a Palindrome";
    else cout<<"\nAha! You got it!";
    cout<<endl;
    system("PAUSE");
    return 0;
}
