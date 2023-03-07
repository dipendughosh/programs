#include<iostream.h>
#include<conio.h>
void main()
{		clrscr();
		int a[3][3],i,j;
		for(i=0;i<3;i++)
				for(j=0;j<3;j++)
						cin>>a[i][j];
		for(i=0;i<3;i++)
		{		for(j=0;j<3;j++)
						cout<<a[i][j]<<"\t";
				cout<<"\n";
		}
		getche();
}


