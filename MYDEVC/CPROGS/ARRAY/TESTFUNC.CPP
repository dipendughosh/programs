#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{   int arr[5]= {23,45,87,1,99};
    void display(int[],int);
    display(arr,5);
     cout<<endl;
     system("PAUSE");
     return 0;
}

void display(int pp[],int n)
{ for(int i=0; i<n; i++)
    cout<<"\n"<<pp[i];
}
