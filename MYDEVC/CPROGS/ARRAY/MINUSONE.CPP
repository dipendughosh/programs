//Deduct one from odd elements of 2D array
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int numarr[4][5],i,j;
    void takearr(int[4][5]);
    void showarr(int[4][5]);
    void changearr(int[4][5]);
    takearr(numarr);
    showarr(numarr);
    for(i=0;i<4;i++)
    {   for(j=0;j<5;j++)
        {   if(numarr[i][j] % 2 == 0) continue;
            numarr[i][j] --;
        }
    }
    cout<<"\nNow the changed array is : \n";
    showarr(numarr);
    cout<<endl;
    system("PAUSE");
    return 0;
}
void takearr(int takenums[4][5])
{   for(int i=0;i<4;i++)
    {   for(int j=0;j<5;j++)
        {   cout<<"Element for Row "<<i+1
                <<" Col "<<j+1<<" : ";
            cin>>takenums[i][j];
        }
    }
}
void showarr(int shonums[4][5])
{   for(int a=0;a<4;a++)
    {   for(int b=0;b<5;b++) cout<<shonums[a][b]<<"\t";
        cout<<endl;
    }
}



