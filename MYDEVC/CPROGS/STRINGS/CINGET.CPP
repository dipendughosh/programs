#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 30
void main()
{   char arr[SIZE];
    int count(char[]);
    for(int x = 0; x < 2; x++){
    cout<<"Enter a line : ";
    cin.getline(arr,SIZE,'\n');
    cout<<arr;
    int noch = count(arr);
    cout<<"\nNo of characters "<<noch;
    cout<<endl;
    }
    system("PAUSE");
}

int count(char a[])
{   int i = 0;
    while(a[i] != '\0') ++i;
    return i;
}
