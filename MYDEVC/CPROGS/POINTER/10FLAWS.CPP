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
{   node* newbox = new node;
    newbox = &box;
    newbox -> next = box.next;
    newbox -> next -> prev = box;
    newbox -> info = n;
    //arrow = newarrow;               OR
    box.next = newbox;
}
void link::showitem()
{   node* current = box.next;  //  OR  arrow;
    while(current != NULL)
    {   cout<<"\nNext = "<<current<<"\t"
            <<"\tData = "<<current->info<<"\n";
        current = current->next;
    }
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
