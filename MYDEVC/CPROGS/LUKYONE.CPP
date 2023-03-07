/* Skipping numbers */

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int arr[10] = {85,2,56,6,52,36,99,58,16,68};
    int num,ctr = 0,i = 0,j = 0,rep = 0;
    for(j = 0; j < 10; j++)
        cout<<arr[j]<<"\t";
    cout<<"Enter a number ";
    cin>>num;
    do
    {   if( arr[i] == 0 )
        {   //i < 9 ? i++ : 0;
            if( i < 9 ) i++;
            else i = 0;
            continue;
        }
        if( ctr == num)
        {   arr[i] = 0;
            rep++;
            ctr = -1;
        }
        ctr++;
        //i < 9 ? i++ : 0;
        if( i < 9 ) i++;
        else i = 0;
    }
    while(rep < 9);
    for(j = 0; j < 10; j++)
        if(arr[j] != 0)
            cout<<"\nThe Lucky number is "<<arr[j];
    cout<<endl;
    system("PAUSE");
    return 0;
}
