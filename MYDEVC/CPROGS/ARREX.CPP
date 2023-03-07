//an array to store 10 nos.
#include <iostream.h>
#include <conio.h>

void main()
{   int array[10],a=0,b=1;
    cout<<"The first ten natural nos. are "<<" ";
    for(;a<10;++a)
    {   array[a]=b;
        b++;
    }
    for(int x=0;x<10;++x)
    cout<<array[x]<<" ";
    getche();
}
