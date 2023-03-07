#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int main()
{   for ( int i=1;i<10;i++)
    {   for( int j=1;j<i+1;j++) cout<<"\t"<<j;
        cout<<endl;
    }
    getche();
    return 0;
}
