#include <iostream.h>
// Number-string conversion to number *** Quanta-3
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

int main()
{   char num[10];
    int i,j;
    double k,number = 0;
    cout<<"Number in string : "; cin.get(num,10);
    for(i=0;i<10;i++)
    {   number = 0;
        for(j=0;j<10;j++)
        {   if(j == 4) k = i;
                else if(j == 9) k = i + 1;
            else k = num[j]-48;
           // cout<<k<<" , ";
            k *= pow(10,( 10 - j - 1 ));
            //cout<<k<<" , ";
            number += k;
        }
        cout<<"\nNumber = "<<number<<endl;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
