#include <iostream.h>
#include <conio.h>

void main()
{   int no=0,num=0,cub=0,n=0,i=0;
    int arr[10];
    cout<<"A number : "; cin>>num;
    n = num;
    while(n>0)
    {   no = n%10;
        n = (n - no)/10;
        arr[i++] = no;
    }
    for(int a = i-1; a>=0; a--)
        cub = cub + (arr[a]*arr[a]*arr[a]);
    if(num==cub) cout<<"Armstrong";
    else cout<<"Not Armstrong";
    getche();
}
