#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   /* char str1[]="sree biswas";
     char* str2="pointer";
     cout<<"str1= "<<str1<<"\n  str2= "<<str2<<"\n  &str2= "<<&str2;
    // str2++; cout<<"\n str2++= "<<str2<<"\n";
    for(int i=0;i<7;i++)
       cout<<str2++<<"\n";*/
    int a[10]={1,2,3,4,5,6,7,8,9,0};
     *a+=1;
    cout<<"*a "<<*a;
   for(int i=0;i<10;i++)
    {*a+=i;
     cout<<*a<<"\n";
    }
    cout<<"\n";
system("PAUSE");
     return 0;
}
