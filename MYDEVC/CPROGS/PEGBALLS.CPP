#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int a[3][4] = {{1,2,3,0}, {4,5,6,0}, {7,8,9,0}};
//int b[3] = {0,0,0}, c[3] = {0,0,0};
//void recur(int,int);
int sum=0;
void show(int,int);
void insert(int,int);
int main()
{
    int x = 0, y = 0;
    //recur(a,b);
    insert(x,y);
    x=0;  y=0;
    show(x,y);

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
       // if (i==3) return;
        j=0;
        insert(i,j);
    }
    if (j<3)
    {   j++;
        insert(i,j);
    }
}


void show(int i, int j)
{
    cout<<a[i][j++]<<"\t";
    if(j < 4) show(i,j);
    else
    {   cout<<endl;
        i++; j = 0;
        if(i < 3) show(i,j);
    }     getche();
}
