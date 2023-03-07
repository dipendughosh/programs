#include <stdlib.h>
#include <string>
void main()
{   string str1,str2,str3;
    void print(string);
    str1="RABINDRANATH";
    print(str1);
    str3.assign(str1,3,3);
    print(str3);
    print(str2);
    cout<<endl;
    system("PAUSE");
}

void print(string s)
{
    for(int i=0;i<s.length();i++) cout<<s[i];
    cout<<endl;
}

