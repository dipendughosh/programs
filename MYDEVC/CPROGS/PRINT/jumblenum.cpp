// Jumbling numbers(4 digits)
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
int main()
{   int arr[4],i=0,j,k,num,num2;
    void swap(int[],int,int),shonum(int[],int);
    do
    {
        cout<<"Enter a 4 digit-number : ";
        cin>>num;
    }
    while(num < 1000 || num > 9999);
    num2 = num;
    while(num2)
    {   arr[i++] = num2 % 10;
        num2 /= 10;
    }
    cout<<"\nThe digits can be jumbled thus :\n";
    for(k = 0; k<4;k++)
    {   for(i = k; i < k+3; i++)
        {   j = 0;
            while(j < 2)
            {   swap(arr,j,j+1);
                shonum(arr,4);
                j++;
            }
        }
        swap(arr,k,3);
    }
    getche();
    return 0;
}

void swap(int arr[],int a,int b)
{   int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void shonum(int arr[],int x)
{   for(int y = 0; y < x; y++)
        cout<<arr[y]<<"\t";
    cout<<endl;
}
