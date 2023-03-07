#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int arr[] = {4,8,3,1,2,4,78},i;
    /*for(i = 0; i < 5 ; i++)
    {   cout<<"Array arr["<<i<<"]is ";
        cin>>arr[i];
    } */
    cout<<"\nOUTPUT :\n";
    for(i = 4; i >=0 ; i--)
        cout<<arr[i]<<"\t";
    cout<<endl;
    system("PAUSE");
    return 0;
}
