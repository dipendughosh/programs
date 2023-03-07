//Sorting
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int num[10] = {34,45,12,6,33,54,98,88,10,92};
    void swap(int&,int&);
    void showarray(int[]);
    cout<<"Original series :\n";
    showarray(num);
    cout<<"\n\nSorting Starts :\n";
    for (int i = 0; i < 9; i++)
    {   for(int j = i+1; j < 10; j++)
           if(num[i] > num[j]) swap(num[i],num[j]);
        showarray(num);
        cout<<"\nStage "<<i+1<<" completed..."<<endl;
        getche();
    }
    cout<<endl;
    system("PAUSE");
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
