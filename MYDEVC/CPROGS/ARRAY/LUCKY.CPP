#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int n,term,start,end,c,count;
    /*cout<<"\n Enter number of terms..  ";cin>>n;
    cout<<"\nsearch term..  ";cin>>term;*/
    int arr[8]={0,1,31,19,11,9,12,78};
    /*cout<<"\nenter variable..  ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    arr[n]=78;
    cout<<n;
    getche();*/
    for(int j=0;j<=8;j++)
        cout<<arr[j]<<"\t";
    start=0;
    end=6;
    do
    {
        c=0;
       // cout<<c;
        while(c=0)
        {
            count=1;
            if(count==term)
            {   cout<<"8i";
                //shifting
                for(int j=start;j<=end;j++)
                    arr[j]=arr[j+1];
                end-=1;
                c=1;

             }
             else
             {
                start+=1;
                if(start>end)
                    start-=(end+1);
                count+=1;
              }

        }
    }
    while(end>0);
    cout<<arr[0];
    cout<<endl;
    system("PAUSE");
    return 0;
}
