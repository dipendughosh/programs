//Insert/Delete nodes in Linked Queue
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct node
{   char alph;
    node *next;
}
*first,*last,*newnode,*temp;
node *creanode(char);
void addinq(node*);
void delinq();
void showq(node*);

void main()
{   first = NULL; last = NULL;
    char letter = 'a';
    while(letter != 'x')
    {   cout<<"\nEnter a character : "; cin>>letter;
        newnode = creanode(letter);
        addinq(newnode);
    }
    cout<<"\nThe present Q is :\n";
    showq(first);
    cout<<"\nNow deleting a node...\n";
    delinq();
    showq(first);
    cout<<endl;
    system("PAUSE");
}

node *creanode(char c)
{   temp = new node;
    temp->alph = c;
    temp->next = NULL;
    return temp;
}
void addinq(node *nd)
{   if(first == NULL)
    {   first = nd;
        last = nd;
    }
    else
    {   last->next = nd;
        last = nd;
    }
}
void delinq()
{   if(first != NULL)
    {   temp = first;
        first = first->next;
        delete temp;
    }
}
void showq(node *qs)
{   while(qs != NULL)
    {   cout<<qs->alph<<" ";
        qs = qs->next;
    }
    cout<<".";
}
