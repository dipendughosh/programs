#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int vote[5]={(0,0,0,0,0)};
    int no,i,count=0;
    do
    {
        cout<<"Voting Option : ";
        cin>>("%d",&no);
        c=no;
        if(no>5)
         {
          cout<<"spoil ballot";
          count++;
         }
         ++vote[no-1];
     }
     while(isdigit(no));
     for(i=1;i<=5;i++)
     cout<<"candidate %d=%3d\n",i,vote[i-1];
     cout<<"\n spoiled ballot=%d",count;
     cout<<endl;
    system("PAUSE");

    return 0;
}
