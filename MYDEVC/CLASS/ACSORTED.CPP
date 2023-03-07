/*to arrange objects of class account in order
according to account no.*/
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class acc
{   int ano,bal;
    public:
    void sort(acc[],int );
    void get();
    void show();
};
void acc::get()
{   cout<<"\n account no ? "; cin>>ano;
    cout<<" balance ? "; cin>>bal;
}
void acc::show()
{   cout<<"\n account no is: "<<ano;
    cout<<"\t balance is: "<<bal;
}

void sort(acc a[],int n)
{   acc t;
    for(int i = 0; i < n; i++)
    {   for(int j = 0; j < n-1-i; j++)
        {   if(a[j].ano > a[j+1].ano)
            {   t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

int main()
{   acc p[3];
    for(int i=0;i<3;i++)
    {   cout<<"\n for object no:"<<i+1;
        p[i].get();
    }
    cout<<"\nRecords in order of input :\n";
    for(int i=0;i<3;i++)
    {   cout<<"\n object no:"<<i+1;
        p[i].show();
    }
    sort(p,3);
    getche();
    cout<<"\n\nsorted in order of A/c No. :\n";
    for(int i=0;i<3;i++)
        p[i].show();
    cout<<endl;
    system("PAUSE");
    return 0;
}
