#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class set
{   int arr[],n;
    public:
        set(int nn) { n = nn; }
        void readElements()
        {   cout<<"\n"<<n;
            for(int i = 0; i < 4; i++)
            {    cout<<"\nEnter data : "<<i<<" ";
                 cin>>arr[i];
            }
        }
        void displayElements()
        {   cout<<"\nThe data is : \n";
            for( int i = 0; i < n; i++)
                cout<<arr[i]<<"\t";
        }
        int getSize() { return n; }
        int has(int ele)
        {   int flag = 0;
            for( int i = 0; i < n; i++)
                if(arr[i] == ele) flag = 1;
            return flag;
        }
        set intersection(set d)
        {   set inter(10);
            int j = 0,dd;
            for( int i = 0; i < d.n; i++)
            {   dd = d.arr[i];
                if(has(dd)) inter.arr[j++] = dd;
            }
            //inter.n = j;
            return inter;
        }
};

int main()
{   set one(4),two(5);
    cout<<"\nEnter data for ONE :\n";
    one.readElements();
    cout<<"\nEnter data for TWO :\n";
    two.readElements();
    one.displayElements();
    two.displayElements();
    getche();
    set three = one.intersection(two);
    //one.displayElements();
    //two.displayElements();
    three.displayElements();
    cout<<endl;
    system("PAUSE");
    return 0;
}
