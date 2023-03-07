#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

struct node
{   int intro;
    node *next;
};
int main()
{
    node *first;          // allocates address for a node
    first->next = NULL;   // 'next' of that addressed node is NULL
    int valu = 0;
    do
    {
        cout<<"Enter value : "; cin>>valu;
        first->intro = valu;   //first-> intro=valu & next=NULL
        node *box = new node;  //allocates address for new node
        box->next = first;     /* new node->next = address of first
                                  but no valu */
        first = box;           /* now 'first' takes the properties
                               of new node i.e., variable 'first'
                               takes over 'box' leaving the
                               previous address.
                               This 'first' is holding the
                               address of its previous node
                               but contains no valu. */
    }
    while (valu > 0);
    cout<<"New node added at the begining...\n";
    node *search = first->next;
    while (search != NULL)
    {
        cout<<search->intro<<"\t";
        search = search->next;
    }

    node* n1,*temp;
    valu = 0;
    n1 = NULL;
    temp = NULL;
    cout<<endl;
    do
    {
        node* n2 = new node;
        cout<<"\nValue : "; cin>>valu;
        n2->intro = valu;
        n2->next = NULL;
        if(n1 == NULL)
        {   n1 = n2;
            temp = n2;
        }
        else
        {   temp->next = n2;
            temp = n2;
        }
    }
    while(valu > 0);
    cout<<"New node appended at the end...\n";
    while(n1->next != NULL)
    {
        cout<<n1->intro<<"\t";
        n1 = n1->next;
    }

    cout<<endl;
    system("PAUSE");
    return 0;
}

