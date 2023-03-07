#include <iostream.h>
#include<iomanip.h>
#include <conio.h>
#include<stdlib.h>

int main()
{   int v;
    cout<<"Enter a number "<<endl;
    cin>>v;
    cout<<"Decimal Base = " << setbase(10);
    cout<<v<<endl;
    cout<<"Hexadecimal base = "<<setbase(16);
    cout<<v<<endl;
    cout<<"Octal base = "<<setbase(8)<<v<<endl;
    cout<<"Eleven base = "<<setbase(11)<<v<<endl;
    system("PAUSE");
    return 0;
}
