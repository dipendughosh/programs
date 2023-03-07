#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int main()
{   int num = 0,i,j;
    while(num<1 || num>20) {
    cout<<"\nEnter a number (Less than 20) : "; cin>>num;
    }
    for (i=num;i>=0;i--) cout<<" "<<i;
    for (int j=1;j<(num+1);j++) cout<<" "<<j;
    getche();
    return 0;
}
