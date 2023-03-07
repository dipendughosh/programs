#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int num[5];
     int *n=num,p=1,r=0,i=0;
     for(;i<5;i++) num[i]=i+1;
     /*while(*n<5)
     {    num[r++]=*n;
          n+=p;
     } */
     r=0;
     while(num[r]<6)
     {    cout<<num[r++]<<endl;
          getche();
     }
     cout<<endl;
     system("PAUSE");
     return 0;
}
