#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int arr[5] = {45,87,51,2,65};
    int *ptr; ptr = arr;
    cout<<"\nCode Without using pointer : \n";
    for(int i = 0; i < 5; i++) cout<<arr[i]<<"\t";
    cout<<"\nCode using pointer concept : \n";
    for(int i = 0; i < 5; i++) cout<<*(arr+i)<<"\t";
    cout<<"\nCode using a pointer       : \n";
    for(int i = 0; i < 5; i++) cout<<*ptr++<<"\t";
    cout<<endl;
    system("PAUSE");
    return 0;
}
