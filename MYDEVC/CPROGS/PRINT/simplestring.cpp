#include <iostream.h>
#include <conio.h>
#include <stdio.h>
class text
{   char txt[20];
    public:
    text() {}
    void readText()
    {   cout<<"Enter a string : "; gets(txt);    }
    char charAt(int i);
    int length();
    int noOfWhiteSpaces();
    int noOfWords();
};
int text::length()
{   int l = strlen(txt);
    return l;
}
char text::charAt(int i)
{   return txt[i-1];   }

int text::noOfWhiteSpaces()
{   int ws = 0;
    for (int x=0; x<strlen(txt); x++)
        if (txt[x] == ' ') ws++;
    return ws;
}

int text::noOfWords()
{   int w = 1;
    for (int x=0; x<strlen(txt); x++)
        if (txt[x] == ' ') w++;
    return w;
}

int main()
{   text t;
    int num;
    t.readText();
    cout<<"\nString Length: "<<t.length();
    cout<<"\nNo of Spaces : "<<t.noOfWhiteSpaces();
    cout<<"\nNo of Words  : "<<t.noOfWords();
    cout<<"\nEnter a number : "; cin>>num;
    if (num <= t.length())
    {   cout<<"\nCharacter at "<<num<<"th place is : ";
        cout<<t.charAt(num);
    }
    else cout<<"\nDestination too far!";
    getche();
    return 0;
}
