//to check if arr is sorted
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void main()
{ clrscr();
  long arr[6];
  for(int i=0;i<6;i++)
	{cout<<" enter no "<<" in pos "<<i+1<<endl;
	 cin>>arr[i];
	}
	long l=arr[0],m=arr[0];
	for(i=0;i<6;i++)
	{ if(l>arr[i])
		l=arr[i];
	  if(m<arr[i])
		 m=arr[i];
	}
	cout<<" lowest "<<l<<"\t"<<" highest "<<m;
	getche();
	if(arr[0]==l)
	 { for(int j=0;j<6;j++)
		{ if(arr[j]<arr[j+1])
		   continue;
		  else
			{cout<<" not sorted ";
			   exit(0);
			}
		}
	   cout<<": asc ";    getche();
	}
	else if(arr[0]==m)
		cout<<" descending order ";
	else
	   cout<<" not sorted ";
  getche();
}
