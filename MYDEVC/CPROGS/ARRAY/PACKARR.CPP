/* to pack array */
/*incomplete*/
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 15
int main()
{   int arr[MAX] = {12,13,14,14,16,17,17,17,19,20,20,21,21,22,23};
    int shoarr(int[],int), i = 0, num = MAX, m;
    shoarr(arr,MAX);
    while(i < MAX)
    {   if(arr[i] == arr[i+1])
        {   //arr[i] = arr[i+1];
            m = i;
            while(arr[++m] == arr[m + 1]) num--;
            arr[i] = arr[m];
        }
        i++;
    }
    shoarr(arr,num);
    cout<<endl;
    system("PAUSE");
    return 0;
}

int shoarr(int mat[],int subs)
{   for(int x = 0; x < subs; x++)
        cout<<mat[x]<<" ";
    cout<<endl;
}
