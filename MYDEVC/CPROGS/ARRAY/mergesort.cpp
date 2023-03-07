// Merging 2 sorted arrays

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

void main()
{   int a[10],b[10],c[20],i,j,n,m,temp,x=0,y=0;
    cout<<"\nEnter size of array A :  ";
    cin>>n;
    cout<<"\nEnter array A :\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"\nEnter size of array B :";
    cin>>m;
    cout<<"\nEnter array B :\n";
    for(i=0;i<m;i++)
        cin>>b[i];
    for(i=0;i<n-1;i++)
    {   for(j=i+1;j<n;j++)
        {   if(a[i]>=a[j])
            {   temp=a[i];
                a[i]=a[j];
                a[j]=temp;
             }
         }
    }
    cout<<"\nARRAY A :\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";

    for(i=0;i<m-1;i++)
    {   for(j=i+1;j<m;j++)
        {   if(b[i]>=b[j])
            {   temp=b[i];
                b[i]=b[j];
                b[j]=temp;
             }
        }
    }
    cout<<"\nARRAY B :\n";
    for(i=0;i<m;i++)
        cout<<b[i]<<"\t";
    cout<<endl;
    for(i=0;i<n+m;i++)
        c[i]=0;
    for(i=0;i<n+m;i++)
    {
        if(a[x]>=b[y])
        {   c[i]=b[y];
                y++;
        }
        else
        {   c[i]=a[x];
            x++;
        }
    }
    cout<<"\nARRAY C :\n";
    for(i=0;i<n+m;i++)
        cout<<c[i]<<"\t";
    getche();

}
