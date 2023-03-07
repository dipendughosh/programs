#include<iostream.h>
#include<conio.h>
void main()
{		clrscr();
		int a[5],b[5],c[10],i,j;
		cout<<"A\n";
		for(i=0;i<5;i++)
		{		cin>>a[i];
		}
		cout<<"B\n";
		for(i=0;i<5;i++)
		{		cin>>b[i];
		}
		for(i=0;i<5;i++)
		{		c[i]=a[i];
		}
		for(j=0;j<5;j++)
		{		c[i+j]=b[j];
		}
		for(i=0;i<10;i++)
		{		cout<<c[i]<<"\n";
		}
		getche();
}