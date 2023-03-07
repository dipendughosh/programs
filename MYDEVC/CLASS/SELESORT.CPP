#include <iostream.h>
#include <conio.h>

class sorter
{   int arr[10];
    public:
        sorter() {}
        void readlist();
        void displaylist();
        int indexofmin(int);
        void selectionsort();
};

void sorter::readlist()
{   cout<<"\nEnter 10 numbers : \n";
    for(int i = 0; i < 10; i++) cin>>arr[i];
}

void sorter::displaylist()
{   cout<<"\nThe numbers are : \n";
    for(int i = 0; i < 10; i++) cout<<arr[i]<<"\t";
}

int sorter::indexofmin(int startindex)
{   int minind = startindex;
    for(int i = startindex+1; i < 10; i++)
        if (arr[i] < arr[minind]) minind = i;
    cout<<"\nSmallest number within the range is : "<<arr[minind];
    return minind+1;
}

void sorter::selectionsort()
{   int temp;
    for(int i = 0; i < 10; i++)
    {   int smallnum = arr[i];
        int smallind = i;
        for(int j = i+1; j < 10; j++)
        {   if(arr[j] < smallnum)
            {   smallnum = arr[j];
                smallind = j;
            }
        }
        temp = arr[i];
        arr[i] = smallnum;
        arr[smallind] = temp;
    }
}

void main()
{   sorter nsort; int stind = -1;
    nsort.readlist();
    nsort.displaylist();
    do
    {   cout<<"\nEnter start-index number ( 1 to 10 ) : "; cin>>stind;
    } while(stind<1 || stind>10);
    cout<<"\nThe index of smallest number"
        <<" from start-index to last : "<<nsort.indexofmin(stind-1);
    nsort.selectionsort();
    cout<<"\nAfter selection-sort:";
    nsort.displaylist();
    getche();
}
