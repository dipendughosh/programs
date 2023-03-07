#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct link
{   int item;
    link *next;
};
class linklist
{   private:
        link* first;
    public:
        linklist()
        {  first->next=NULL;  }
        void  putitem(int input)
        {   //int input;
            //cout<<"no  ?";    cin>>input;
            link *newlink=new link;
            newlink->item=input;
            newlink->next=first;
            first=newlink;
            //delete newlink;
        }
        void display();
        //void displayat(int );
};

void linklist::display()
{  link *current=first;
    while( current!=NULL )
    {   cout<<"\ndisplaying  "<<current->item;
        //getche();
        current=current->next;
    }
 }
/* void linklist::displayat( int position)
{   link *current=first;    int c=0;
    while( current!=NULL )
    {    c++;
         cout<<"item till given position is  "<<current->item;
         current=current->next;
         if(c==position)
               break;
    }
} */
int main()
{
    linklist obj;

    //for( int i=0;i<5;i++)
        obj.putitem(23);
        obj.putitem(29);
        obj.putitem(275);
        obj.putitem(926);
    //getche();
    obj.display();
    //obj.displayat(3);
    cout<<endl;
    system("PAUSE");
    return 0;
}
