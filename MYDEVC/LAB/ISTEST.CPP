#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
int main()
{
    char no;
    cin>>no;
    cout<<isalpha(no);getche();
    if(isalpha(no)) cout<<"Alphabet";
    else cout<<"No";
    cout<<endl;
    system("PAUSE");
    return 0;
}
