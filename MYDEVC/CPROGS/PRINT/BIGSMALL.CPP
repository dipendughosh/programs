// Finding the largest/Smallest values
//and their respective position in single D/array

#include <iostream.h>
#include <conio.h>

void main()
{   int arr[10], large = 0, lsub = 0,  small = 32767, ssub = 0;
    int cheklarge(int,int), cheksmall(int,int);
    for(int i=0; i<10; i++)
    {   cout<<"\nenter 10 digits : ";
        cin>>arr[i];
        if(cheksmall(small,arr[i]))
        {   small = arr[i];
            ssub = i+1;
        }
        if(cheklarge(large,arr[i]))
        {   large = arr[i];
            lsub = i+1;
        }
    }
    cout<<"\nLargest is : "<<large<<" in "<<lsub;
    cout<<"\nSmallest is : "<<small<<" in "<<ssub;
    getche();
}

int cheklarge(int l, int n)
{   if (n > l) return 1;
    else return 0;
}

int cheksmall(int s, int n)
{   //cout<<s<<"\tnum "<<n<<"\n";
    if (n < s) return 1;
    else return 0;
}
