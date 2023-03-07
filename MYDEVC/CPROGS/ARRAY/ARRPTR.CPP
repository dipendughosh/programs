#include <iostream.h>
#include <stdlib.h>

int main()
{   int arr[] = {12,25,65,87,98};
    int* ptr = arr;
    int i = 0;
    while(i < sizeof(arr)/4)
        cout<<ptr[i++]<<endl;
    cout<<endl;
    system("PAUSE");
    return 0;
}

