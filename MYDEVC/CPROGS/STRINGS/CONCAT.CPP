#include <iostream.h>
#include <conio.h>
#include <string.h>

int main()
{   char s1[80],s2[80];
    cout<<"Enter 1st. word : "; cin>>s1;
    cout<<"\nEnter 2nd. word : "; cin>>s2;
    cout<<"\n";
    cout<<strncat(s1,s2,1);
    getche();
    return 0;
}
