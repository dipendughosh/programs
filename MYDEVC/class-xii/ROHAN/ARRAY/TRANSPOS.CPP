// the transpose
#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	int matrix[20][20];
	int c,r,g=0;
	cout<<" enter the no of rows  ";
	cin>>r;
	do
	 { cout<<" enter the column";
		 cin>>c;
	 }while(r!=c);
	for(int i=0;i<r;i++)
	{ for(int j=0;j<c;j++)
	  {cout<<"\t elements?";
		cin>>matrix[i][j];
	  }
	}
	for(i=0;i<r;i++)
	 { for(int j=0;j<r;j++)
	   {if(matrix[i][j]==matrix[j][i])
		 g++;
	   }
	 }
	 if(g==c*c)
	  cout<<" transpose matrix ";
	 else
	  cout<<" not transpose ";
	  getche();
 }