#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int arr[5] = {7,5,9,4,6}, n,i,j,p;
    for(p=0;p<5;p++)
        cout<<arr[p]<<"\t";
    cout<<endl;
    for(i = 0; i < 5; i++)
    {   if (arr[i] == 5)
        {   n = 5;
            for(j = i; j < 5-1; j++)
                arr[j] = arr[j+1];
            arr[4] = 58;
            //break;
        }
    }
    for(p=0;p<5;p++)
        cout<<arr[p]<<"\t";
    cout<<endl;
    system("PAUSE");
    return 0;
}
