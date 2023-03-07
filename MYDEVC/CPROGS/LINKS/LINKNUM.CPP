#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct link
{   int data;
    link* next;                 // pointer to the next link
};
class linklist
{   private:
        link* first;            // ponter to first link
    public:
        linklist()
        {   first = NULL;
        }                       // no first link
        void additem(int);
        void showitem();
};
void linklist::additem(int d)
{   link* newlink = new link;   // creating a new link
    newlink -> data = d;
    newlink -> next = first;
    first = newlink;
}
void linklist::showitem()
{   link* current = first;
    while ( current != NULL )
    {   cout<<current -> data<<",";
        current = current -> next;
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
