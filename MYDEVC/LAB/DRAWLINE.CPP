#include <iostream.h>
#include <conio.h>

void main()
{   void draw(char,int);
    char s = '*';
    for(int p=1,q=10; p<=10; p++,q--)
    {   draw(s,p);
        cout<<"\t";
        draw(s,q);
        cout<<endl;
    }
    getche();
}

void draw(char x,int y)
{   for(int i=0; i<y; i++) cout<<x; }
