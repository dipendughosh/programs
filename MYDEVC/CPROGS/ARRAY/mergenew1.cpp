//Merge Sort with pointers

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int two[] = {4,5,8,9,12,15};
int one[] = {5,9,11,15,21,24,48,50,58};
int a = sizeof(one)/4, b = sizeof(two)/4;
int main()
{
    const int s = a + b;
    int three[s];
    void showarr(int[],int size);
    int *small, *big, *temp;
    int sm, bg, x = 0, y = 0, cont = 0;
    if(a <= b)
    {   sm = a; bg = b;
        small = one; big = two;
    }
    else
    {  sm = b; bg = a;
       small = two; big = one;
    }
    showarr(one,a); showarr(two,b);
    int i = 0;
    while(x < sm)
    {   if(small[x] == big[y])
        {   three[i++] = small[x++];
            three[i++] = big[y++];
        }
        else
        {   if(small[x] < big[y]) three[i++] = small[x++];
            else three[i++] = big[y++];
        }
    }
    while(i <= s) three[i++] = big[y++];
    showarr(three,s);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void showarr(int ary[],int z)
{   cout<<endl;
    for(int p = 0; p < z; p++)
        cout<<ary[p]<<"  ";
    cout<<endl;
}
