#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
    int arr[10]={3,4,3,5,6,3,6,3,8,5},arr2[100];
    int i,num,j,t = 9,k,l = 1;
    for(i = 0;i<10;i++)
    {
        num = arr[i];
        for(j= i+1;j<10;j++)
        {
            if(num == arr[j])
            {
               arr[j] = 0;
               arr[i] = 0;
            }
        }
       // arr[i] = 0;
        for(int p= 0;p<10;p++)
            cout<<arr[p]<<" ";
        cout<<"\n";
        getche();
    }

    for(i = 0;i<10;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    getche();
}
