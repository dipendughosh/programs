#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

struct length
{   int feet;
    int inches;
    int len;
};

int main()
{   length n[3];
    for (int i=0; i<3; i++)
    {   cout<<"\nEnter n-feet : "; cin>>n[i].feet;
        cout<<"Enter n-inches : "; cin>>n[i].inches;
        n[i].len = n[i].feet*12+n[i].inches;
    }
    //m = n;
    cout<<"\nlength : "<<n[2].len;
    //cout<<"\tinches : "<<m.inches;
     cout<<endl;
     system("PAUSE");
     return 0;
}
