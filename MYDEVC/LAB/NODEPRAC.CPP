#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

struct node
{   int intro;
    node *next;
};
int main()
{
    node first,box,newbox,search;
    int i;
    first.intro = 0;
    first.next = &box;
    for(i = 45; i < 50; i++)
    {
        box.intro = i;                      // 45  46
        box.next = &newbox;                 // xxi xxi
        newbox = box;
        cout<<newbox.intro<<endl;           // 45  xxi
    }
    box.intro = i;
    box.next = NULL;
    search = first;
    while(search.next != NULL)
    {
        cout<<search.intro<<endl;
        search.next = &newbox;
        search = box;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
