//Bubble-Sort
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int num[10] = {34,45,12,6,33,54,98,88,10,92};
    void swap(int&,int&);
    void showarray(int[]);
    cout<<"Original series :\n";
    showarray(num);
    cout<<"\n\nBubble-Sorting Starts :\n";
    for (int i = 0; i < 10; i++)
    {   for(int j = 0; j < 9-i; j++)
           if(num[j] > num[j+1])
           { swap(num[j],num[j+1]);
             showarray(num);cout<<endl;
           }
        cout<<"\nStage "<<i+1<<" completed..."<<endl;
        getche();
    }
    cout<<endl;
    system("\nPAUSE");
    return 0;
}

void swap(int& n1,int& n2)
{   int temp;
    temp = n1; n1 = n2; n2 = temp;
}

void showarray(int numarr[])
{   for(int x = 0; x < 10; x++)
        cout<<numarr[x]<<"  ";
}
