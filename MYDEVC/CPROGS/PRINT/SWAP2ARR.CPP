#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   char arr[4][4];
    void showarr(char arr[4][4]);
    void swaparr(char arr[4][4],int,int);
    char n = 97;
    for(int i=0;i<4;i++)
    {   for(int j=0;j<4;j++)
        {   arr[i][j] = n;
            n++;
        }
    }
    cout<<"The original array is :\n\n";
    showarr(arr);
    for(int r=0;r<4;r++)
    {   swaparr(arr,r,3);
        swaparr(arr,1,2);
    }
    cout<<endl;
    cout<<"The changed array is :\n\n";
    showarr(arr);
    cout<<endl;
    system("PAUSE");
    return 0;
}
void showarr(char mat[4][4])
{   for(int x=0;x<4;x++)
    {   for(int y=0;y<4;y++)
            cout<<mat[x][y]<<"\t";
        cout<<endl;
    }
}
void swaparr(char mat[4][4],int x,int y)
{   char temp = 48;
    temp = mat[x][0];
    mat[x][0] = mat[x][y];
    mat[x][y] = temp;
}
