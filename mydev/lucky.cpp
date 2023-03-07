// Step1: skips 1 no.; Step2: skips 2 nos. and so on...
#include <iostream.h>
#include <conio.h>

int main()
{  int i,k,l,n,skip=2,arr[50];
   cout<<"\nEnter n";
   cin>>n;
   for(i=0;i<n;i++)
       arr[i]=i+1;            
   l=n;
   do
   {   k=0;
       for(i=0;i<l;i+=skip)
             arr[k++]=arr[i];
       l=k;
       skip++;
   }while(skip<=l);          
   for(i=0;i<l;i++)
       cout<<arr[i]<<"\t"; 
   getche();return 0;
}