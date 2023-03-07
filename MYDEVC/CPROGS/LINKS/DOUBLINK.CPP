#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct node
{   int info;
    node* next;
    node* prev;
};
class link
{   private:
        node box;
    public:
        link()
        {   box.next = NULL;
            box.prev = NULL;
        }
        void additem(int);
        void showitem();
};
void link::additem(int n)
{   node* newbox = new node;          // "newbox" is a new node
    newbox = &box;
    newbox -> next = new node;        /* next of "newbox" is a pointer
                                         to next-new box */
    newbox -> next -> prev = newbox;  // prev of next-new box is "newbox"
    newbox = newbox -> next;
    newbox -> info = n;
    //newbox  = newbox -> next;
    newbox -> next = NULL;
}
void link::showitem()
{   node* newbox = box.next;
    do
    {   cout<<"\nNext = "<<newbox<<"\t"
            <<"\tData = "<<newbox->info<<"\n";
        newbox = newbox -> next;
    } while (newbox -> next);
    do
    {   cout<<"\nNext = "<<newbox<<"\t"
            <<"\tData = "<<newbox->info<<"\n";
        newbox = newbox -> prev;
    } while (newbox -> prev);
}
int main()
{   link obj;
    int number;
    for(int i = 0; i<4; i++)
    {   cout<<"Data for node "<<i+1<<": ";
        cin>>number;
        obj.additem(number);
    }
    cout<<"\n\nThe output :\n";
    obj.showitem();
    cout<<endl;
    system("PAUSE");
    return 0;
}
