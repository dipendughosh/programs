//Largest sum from which range?
#include <iostream.h>
#include <conio.h>

void main()
{   int num[6] = { 4,-8,6,-2,5,-4 };
    int numsum(int[],int,int);
    int large = num[0],retsum,start=0,end=6;
    cout<<"\n\tThe numbers are :\n";
    for(int t=0; t<6; t++) cout<<"\t"<<num[t];
    cout<<endl;
    for(int i=0; i<5; i++)
    {   for(int j=i+1; j<6; j++)
        {   retsum = numsum(num,i,j);
            //cout<<retsum<<endl;
            if (retsum>large)
            {   large = retsum;
                start = i; end = j;
            }
        }
     }
     cout<<"\nLargest sum is "<<large<<"\n"
        <<"Range is from position "<<start+1<<" to "<<end+1;
     getche();
}

int numsum(int n[],int p,int q)
{   int s = 0;
    for(int x=p; x<=q; x++) s+=n[x];
    return s;
}
