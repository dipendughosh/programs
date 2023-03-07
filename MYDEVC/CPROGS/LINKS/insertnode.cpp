#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct box
{   int data;
    box *address;
};
int main()
{   box *temp,*newbox,*into,*store;
    int ins, after;
    void showlist(box*);
    temp = NULL;
    for(int i = 0; i < 5; i++)
    {   newbox = new box;
        cout<<"\nEnter data for list : ";
        cin >> newbox->data;
        newbox->address = temp;
        temp = newbox;
    }
    /* During insertion, the list is to be run and
       the properties of present 'newbox' will be lost.
       Hence, a copy of 'newbox' is kept in 'store',
       otherwise, revised list can not be printed */
    store = newbox;
    showlist(store);
    cout << "\nEnter number to insert : "; cin >> ins;
    cout << "\nAfter which number ?     "; cin >> after;
    do
    {   if(temp->data == after)
        {   into = new box;
            into->data = ins;
            into->address = temp->address;
            temp->address = into;
            break;
        }
        temp = temp->address;
    } while(temp->address);
    showlist(store);
    cout << endl;
    system("PAUSE");
    return 0;
}

void showlist(box *chain)
{
    while(chain->address)
    {   cout << chain->data << "\t";
        chain = chain->address;
    }
    cout << chain->data;
}
