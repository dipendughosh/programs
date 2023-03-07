#include<iostream.h>
#include<conio.h>
void main()
{		clrscr();
		int a[3][3],left=0,right=0,i,j,row=0,col=0,n;
		for(i=0;i<3;i++)
				for(j=0;j<3;j++)
						cin>>a[i][j];
		cout<<"\n\tA\n";
		for(i=0;i<3;i++)
		{		for(j=0;j<3;j++)
						cout<<a[i][j]<<"\t";
				cout<<"\n";
		}
		for(i=0;i<3;i++)
		{		j=i;
				left=left+a[i][j];
		}
		j=2;
		for(i=0;i<3;i++)
		{		right=right+a[i][j];
				j--;
		}
		cout<<"SUM OF LEFT DIAGONAL ="<<left;
		cout<<"\nSUM OF RIGHT DIAGONAL ="<<left;
		for(i=0;i<3;i++)
		{		for(j=0;j<3;j++)
				{		row=row+a[i][j];
						n=i;
				}
				cout<<"\nSUM OF ROW "<<++n<<" IS "<<row;
				row=0;
		}
		for(j=0;j<3;j++)
		{		for(i=0;i<3;i++)
				{		col=col+a[i][j];
						n=j;
				}
				cout<<"\nSUM OF COLUMN "<<++n<<" IS "<<col;
				col=0;
		}
		getche();
}