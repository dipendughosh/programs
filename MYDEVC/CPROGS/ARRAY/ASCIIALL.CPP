#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int i=0,j=0;
    for(i=0;i<=256;i++)
    {   j++;
        if(i!=26)
        {   cout<<i<<"-"<<(char)i<<" ";
            if(j==13)
            {   cout<<"\n\n";
                j=0;
                //getche();
            }
        }
        else
        {   cout<<i<<"-  ";
        }
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}



