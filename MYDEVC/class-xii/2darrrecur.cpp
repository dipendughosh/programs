#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int i,j;
    int array[10][10];
    void input(int [10][10],int,int);
    cout<<"\nEnter number of rows :-> ";
    cin>>i;
    cout<<"\nEnter number of columns :-> ";
    cin>>j;
    input(array,i,j);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void input(int array[10][10],int i,int j)
{   int x=0,y=0;
    if(x <= i)
    {   if(y <= j)
        {   cout<<"\nEnter element-> ";
            cin>>array[x][y];
            y++;
            input(array,i,j);
        }
        else
        {   x++;
            y=0;
            input(array,i,j);
        }
    }

}
