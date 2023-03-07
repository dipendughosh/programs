#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define x 10
class que
{   private:
    int arr[x],start,rear;
    public:
    que();
    void add();
    void del();
    void display();
    ~que();
};

que::que()
{   start=-1;
    rear=-1;
}

void que::add()
{   int w;
    if(start==-1)
        start=0;
    cout<<"\nEnter value to add at end->";
    cin>>w;
    if(rear>=x-1)
        cout<<"\nOverflow!!!!!!!!";
    else
        arr[++rear]=w;
}

void que::del()
{   if(start>rear)
        cout<<"\nUnderflow!!!!!!!";
    else
        start++;
}

void que::display()
{   int i;
    cout<<"\n";
    for(i=start;i<=rear;i++)
        cout<<arr[i]<<"\t";
}

que::~que()
{
}

void main()
{   que q;
    int c;
    char ch;
    do
    {
        cout<<"\n\t\tMENU";
        cout<<"\n\t\t1.ADD";
        cout<<"\n\t\t2.DELETE";
        cout<<"\n\t\t3.EXIT";
        cout<<"\n\t\tEnter choice->";
        cin>>c;
        switch(c)
        {   case 1:
                q.add();
                q.display();
                break;
            case 2:
                q.del();
                q.display();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"\nWrong choice";
                break;
        }
        cout<<"\nDo you want to continue?";
        cin>>ch;
    }
    while(ch!='n' || ch!='N');
    cout<<endl;
    system("PAUSE");
}
