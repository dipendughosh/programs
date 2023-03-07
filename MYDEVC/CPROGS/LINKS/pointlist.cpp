#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct box
{   int data;
    box *address;
};
int main()
{   box *temp,*newbox;
    temp = NULL;
    char ch='y';
    while(ch=='y')
    {   cout<<"\nAddress of temp="<<&temp;
        newbox = new box;
        cout<<"\nAddress to which newbox point's="<<newbox->address;
        cout<<"\nAddress of new newbox="<<&newbox;getche();
        cout<<"\nEnter data : ";
        cin >> newbox->data;
        newbox->address = temp;
        //cout<<"\nAddress held in temp="<<temp->address;
        cout<<"\nAddress held in newbox="<<newbox->address;
        temp = newbox;
        cout<<"\nAddress held in temp="<<temp->address;
        cout<<"\nAddress held in newbox="<<newbox->address;
        cout<<"\nWant to enter data....";cin>>ch;
    }
    cout << "\nNow, the output :\n";
    do
    {   cout << newbox->data << "\t";

        newbox = newbox->address;
    }
    while(newbox->address!=NULL);
    cout << newbox->data;
    cout << endl;
    system("PAUSE");
    return 0;
}

