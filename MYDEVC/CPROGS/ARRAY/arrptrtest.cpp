#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{   int arr[3] = { 12,54,65};
    int* ptr;
    ptr = arr;
    cout<<ptr[1];
    cout<<ptr[2];
    cout<<endl;
    system("PAUSE");
    return 0;
}
