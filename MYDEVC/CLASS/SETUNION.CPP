// this 2003 prog is incomplete
#include <iostream.h>
#include <conio.h>

class set
{   int arr[50],n;
    public:
    set(int nn) { n = nn; }
    set() { n = 0; }
        void readelements();
        void displayelements();
        int getsize()
            {   return n; }
        int has(int);
        set intersection(set);
        set unions(set);
};
void set::readelements()
{   cout<<"\nEnter the elements :\n";
    for (int i = 0; i < n; i++) cin>>arr[i];
}
void set::displayelements()
{   cout<<"\nThe elements are :\n";
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
}
int set::has(int ele)
{   int found = 0, i = 0;
    while(!found || i < n)
       if(ele == arr[i++]) found = 1;
    return found ;
}
set set::intersection(set d)
{   set temp; int x = 0;
    for(int i = 0; i < n; n++)
    {    for(int j = 0; j < n; n++)
            if(arr[i] == d.arr[j]) temp.arr[x++];
    }
    return temp;
}
void main()
{   set one(6),two(5); int num;
    cout<<"\nCase One : \n";
    one.readelements();
    one.displayelements();
    cout<<"\nNumber to search : "; cin>>num;
    cout<<one.has(num);
    cout<<"\nCase Two : ";
    two.readelements();
    set three = one.intersection(two);
    cout<<"\nCase Three : \n";
    three.displayelements();
    getche();
}
