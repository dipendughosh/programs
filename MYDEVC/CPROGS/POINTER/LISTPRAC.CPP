#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct node
{   int data;
    node *loca;
};
void main()
{   node *newnode, *temp;
    newnode = NULL;
    for(int i = 0; i < 4; i++)
    {   temp = new node;
        cout<<"Data : "; cin>>temp->data;
        temp->loca = newnode;
        newnode = temp;
        cout<<newnode->data<<"\t"<<newnode->loca<<"\n";
    }
    temp = newnode;
    cout<<"\nNow output===>\n";
    while(temp != NULL)
    {   cout<<temp->data<<"\t"<<temp->loca<<"\n";
        temp = temp->loca;
    }
    cout<<endl;
    system("PAUSE");
}
