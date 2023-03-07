#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int a[4][4],b[4][4],c[4][4],i,j,k;
    cout<<"\tA\n";
    for(i = 0;i < 4;i++)
        for(j = 0;j < 4;j++)
            cin>>a[i][j];

    cout<<"\tB\n";
    for(i = 0;i < 4;i++)
        for(j = 0;j < 4;j++)
            cin>>b[i][j];
    for(i = 0;i < 4;i++)
        for(j = 0;j < 4;j++)
            c[i][j] =0;

    for(i = 0;i < 4;i++)
        for(j = 0;j < 4;j++)
            for(k = 0;k < 4;k++)
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);

    cout<<"\tA\n";
    for(i = 0;i < 4;i++)
    {    for(j = 0;j < 4;j++)
        {    cout<<a[i][j]<<"\t";

        }
        cout<<"\n";
     }
    cout<<"\n\tB\n";
    for(i = 0;i < 4;i++)
    {    for(j = 0;j < 4;j++)
        {    cout<<b[i][j]<<"\t";

        }
        cout<<"\n";
     }
     cout<<"\n\tC\n";
    for(i = 0;i < 4;i++)
    {    for(j = 0;j < 4;j++)
        {    cout<<c[i][j]<<"\t";

        }
        cout<<"\n";
     }
    cout<<endl;
    system("PAUSE");
    return 0;
}
