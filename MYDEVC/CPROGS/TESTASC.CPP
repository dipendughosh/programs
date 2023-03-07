#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int row,q;
    int arr[500][500];
    cout<<"\n Enter row ...";cin>>row;
    q=row/2;
    if(row%2==1)
        q+=1;
    int p=1,start=0,end=row-1;
    for(int i=1;i<=q;i++)
    {
        for(int j=start;j<=end;j++)
        {
            arr[start][j]=p;
            p++;
        }
        for(int k=start+1;k>=end;k++)
        {
            arr[k][end]=p;
            p++;
        }
        for(int l=row-1-start-1;l>=start;l--)
        {
            arr[row-1-start][l]=p;
            p++;
        }
        for(int m=end-1;m>=start+1;m--)
        {
            arr[m][start]=p;
            p++;
        }
        start++;
        end--;
    }
    for(int r=0;r<row;r++)
    {
        for(int c=0;c<row;c++)
            cout<<arr[r][c]<<" ";
        cout<<endl;
    }
    getche();
}


