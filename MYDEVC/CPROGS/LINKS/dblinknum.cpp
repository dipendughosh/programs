#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct link
{   int data;
    link* next;
    link* previous;            // pointer to the next link
};
class linklist
{   private:
        link* first;            // pointer to first link
    public:
        /*linklist()
        {   first = NULL;
        }                       // no first link*/
        void additem(link*);
        void showitem(link*);
};
void linklist::additem(link* node)
{   //link* newlink = new link;
    first.next = NULL;
    first.previous = NULL;
    node = &first;   // creating a new link
    link node = new node;
    node -> data = d;
    node -> next = node;
    node -> next -> previous = node;
    node -> next = NULL;
}
void linklist::showitem()
{   //link* current = first;
    node = first.next;
    while ( node -> next )
    {   cout<<current -> data<<",";
        node = node -> next;
    }
}

int main()
{   linklist ll;
    long num;
    int n,i = 0;
    cout<<"\nEnter a number : "; cin>>num;
    while ( num)
    {   ll.additem(num % 10);
        num /= 10;
    }
    cout<<"\n\nThe digits are : ";
    ll.showitem();
    cout<<endl;
    system("PAUSE");
    return 0;
}
