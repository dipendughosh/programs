//TO CHECK IF AN ARRAY IS SORTED AND THEN , ASCENDING OR DESCENDING
#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
   long arr[5];
   int a=1,d=1,i;
   for(i=0;i<5;i++)
	 {cout<<" enter no in position "<<i+1<<endl;
	   cin>>arr[i];
	 }
   for(i=0;i<5;i++)
	{ if(arr[i]<arr[i+1])
	   a++;
	 if(arr[i]>arr[i+1])
	  d++;
	}
	if(a==5)
	 cout<<" ascending ";
	else if(d==5)
	 cout<<" descending ";
   else
	cout<<" not sorted";
 getche();
}
