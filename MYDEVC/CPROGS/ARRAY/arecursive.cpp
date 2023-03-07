//Incomplete
#include <iostream.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>

int a[3][4]={{1,2,3,0},
             {4,5,6,0},
             {7,8,9,0}};
int sum=0;
int main()
{   int i=0,j=0;
    //void insert(int i,int j);
    void print(int i,int j);
    //insert(i,j);
    i=0;  j=0;
    print(i,j);cout<<"!!!\n";
    cout<<endl;
    system("PAUSE");
    return 0;
}

void insert(int i,int j)
{   sum+=a[i][j];
    if (j==3)
    {   a[i][j]=sum;
        sum=0;
        i++;
        if (i==3) return;
        j=0;
        insert(i,j);
    }
    if (j<3)
    {   j++;
        insert(i,j);
    }
}

void print (int i,int j)
{
    while(j < 4) cout<<a[i][j++]<<"  ";
    ++i; j = 0;
    cout<<endl;
    if( i == 3) return;
    else print(i,j);
}

