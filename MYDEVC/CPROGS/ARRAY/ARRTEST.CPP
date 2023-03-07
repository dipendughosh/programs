#include <iostream.h>
#include <conio.h>

void main()
{   int arr[5],no;
    void fillarr(int[],int);
    void shoarr(int[],int);
    int chek(int[],int);
    fillarr(arr,5);
    shoarr(arr,5);
    cout<<"\nEnter a number : "; cin>>no;
    if (chek(arr,no))
        cout<<"\n\aYes the number is contained in the array .";
    else
        cout<<"\n\aNo the number is not contined in the array .";
    getche();
}

void fillarr(int a[],int n)
{   for(int i = 0; i < n; i++) cin>>a[i];
}

void shoarr(int a[],int n)
{   for(int i = 0; i < n; i++) cout<<a[i]<<"\t";
}


int chek(int s[],int q)
{   for(int y=0;y<5;y++)
       if(s[y]==q) return 1;
    return 0;
}
