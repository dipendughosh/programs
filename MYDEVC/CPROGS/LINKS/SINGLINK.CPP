// Creating Singly-linked list
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct node
{   int info;
    node* next;
};
class link
{   private:
    node* box;
    public:
    link()
    {   box -> next = NULL;}
    void additem(int);
    void showitem();
};
void link::additem(int n)
{   node* newbox = new node;
    newbox -> next = box;
    box -> info = n;
    box = newbox;
}
void link::showitem()
{   node* current = box -> next;
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
