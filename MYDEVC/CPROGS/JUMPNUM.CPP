//2 check
#include <iostream.h>
#include <conio.h>

void main()
{   //void display(int)
    int n[10], jump = 1, x;
    for(int i=0; i<10; i++) n[i]=i+1;
    for (x=0;x<10;x++) cout<<n[x]<<"\t";
    getche();
    while(jump<10)
    {   for(int j=0; j<10-jump; j++)
        {   cout<<n[j+jump]<<"\t";
            if (n[j+jump]) n[j+jump]= 0;
            cout<<n[j+jump]<<"\n";
        }
        for (x=0;x<10;x++) cout<<n[x]<<"\t";
        getche();
        jump++;
    }
    for(int k=0; k<10; k++)
        if(n[k]>0) cout<<n[k]<<"\t";

    getche();
}

void display(int arr[])
{   for (int x=0;x<10;x++) cout<<arr[x]<<"\t<<";
}
