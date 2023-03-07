#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{

    int a[5][5]={{1,2,3,4,5},
                 {6,7,8,9,10},
                 {11,12,13,14,15},
                 {16,17,18,19,20},
                 {21,22,23,24,25}};
    void print(int[5][5],int,int);
    //void input(int [][]);
    print(a,0,0);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void print(int x[5][5],int y,int row)
{

    //if(count <=(5*5))//(row*col)
       if(y<=4)
        {
            cout<<" "<<x[row][y];
            y++;
         }
        else
        {
            cout<<endl;
            row++;
            y=0;
            if(row==5)
                return;
        }
        print(x,y,row);
}

