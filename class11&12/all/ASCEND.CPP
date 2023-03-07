//ascending order
#include<iostream.h>
#include<conio.h>
void main()
{   clrscr();
		int a[10],i,j,b;
		for(i=0;i<10;i++)
		{		cout<<"a["<<i<<"] = ";
				cin>>a[i];
		}
		for(i=0;i<10;i++)
		{		for(j=i+1;j<10;j++)
				{		if(a[i]>a[j])
						{   b=a[i];
						    a[i]=a[j];
						    a[j]=b;
						}
				}
		}
		cout<<"ASCENDING ARAY IS\n";
		for(i=0;i<10;i++)
		{		cout<<"a["<<i<<"] = "<<a[i]<<"\n";
		}
		getche();
}