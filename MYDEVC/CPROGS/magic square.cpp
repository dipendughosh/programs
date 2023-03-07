#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int a[9][9],i,j,input;
    cout<<"Enter a value : ";  cin>>input;
    int ctr=1,n=input-1,row=0,col=n/2;
    for (i=0;i<input;i++)
        for (j=0;j<input;j++)
            a[i][j]=0;
    while (ctr<=input*input)
    {   a[row--][col++]=ctr++;
        if (row<0)
        {   if (col>n)
            {    row+=2;
                 col--;
            }
            else row=n;
        }
        else
        {   if (col>n)  col=0;
            else if (a[row][col]>0)
                 {  row+=2;  col--;
                 }
        }
    };
    int sum=0;
    for (i=0;i<input;i++)
    {   sum=0;
        for (j=0;j<input;j++)
        {   sum+=a[i][j];
            cout<<a[i][j]<<"\t";
        }
       // cout<<"\t\tSum="<<sum;
        cout<<endl<<endl;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
