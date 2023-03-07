// Creating/Adding 2D arrays (with a difference)
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
void main()
{   char arr1[4][5], arr2[4][5], arr3[4][5];
    void showarr(char [4][5]);
    char alph, numb;
    int i, n;
    for ( i=0,n=3,alph=65; i < 4; i++,n--,alph++)
    {   numb = 49;
        for (int j = 0; j < 5; j++)
        {   if (j > n) arr1[i][j] = numb++;
            else arr1[i][j] = alph;
        }
    }
    cout<<"\nFirst Array :\n";
    showarr(arr1);
    cout<<endl;
    for ( i=0,n=3,numb=49; i < 4; i++,n--,numb++)
    {   alph = 65;
        for (int j = 0; j < 5; j++)
        {   if (j > n) arr2[i][j] = alph++;
            else arr2[i][j] = numb;
        }
    }
    cout<<"\nSecond Array :\n";
    showarr(arr2);
    for ( i = 0; i < 4; i++)
    {   for (int j = 0; j < 5; j++)
           arr3[i][j] = arr1[i][j] + arr2[i][j];
    }
    cout<<"\n\nResultant Array :\n";
    showarr(arr3);
    cout<<endl;
    system("PAUSE");
}

void showarr(char mat[4][5])
{   for(int x = 0; x < 4; x++)
    {   for(int y = 0; y < 5; y++)
            cout<<mat[x][y]<<"\t";
        cout<<endl;
    }
}

