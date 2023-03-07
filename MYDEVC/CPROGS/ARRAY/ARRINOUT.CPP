#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   //void getData(int[],int),showData(int[],int);
    //void compCommon(...), void addUncommon(...);
    int addarr();
    int arr[7];
    arr[7] = addarr();
    cout<<endl;
    cout<<addarr();
    cout<<endl;
    /*for(int k = 0; k < 7; k++)
        cout<<arr[k]<<"\t";*/
    cout<<endl;
    system("PAUSE");
    return 0;
}

int addarr()
{   int arr1[3] = { 4,5,8};
    int arr2[4] = { 5,9,12,4};
    int arr3[3+4],  p = 0;
    for(int i = 0; i < 3; i++)
        arr3[p++] = arr1[i];
    for(int j = 0; j < 4; j++)
        arr3[p++] = arr2[j];

    for(int k = 0; k < 10; k++)
        cout<<arr3[k]<<"\t";

    return (arr3[9]);
}




