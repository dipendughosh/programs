#include<iostream.h>
#include<conio.h>
void main()
{		clrscr();
		int a[3][3],left=0,right=0,i,j,row=0,col=0,s=0;
		for(i=0;i<3;i++)
				for(j=0;j<3;j++)
						cin>>a[i][j];
		cout<<"\n\tA\n";
		for(i=0;i<3;i++)
		{	for(j=0;j<3;j++)
				cout<<a[i][j]<<"\t";
			cout<<"\n";
		}
		for(i=0;i<3;i++)
		{	j=i;
			left=left+a[i][j];
		}
		j=2;
		for(i=0;i<3;i++)
		{	right=right+a[i][j];
			j--;
		}
		for(i=0;i<3;i++)
		{	for(j=0;j<3;j++)
			{	s=s+a[i][j];
			}
			row=row+s;
			cout<<"\nSUM OF ROW "<<i+1<<" = "<<s;
			s=0;
		}
		s=0;
		for(i=0;i<3;i++)
		{	for(j=0;j<3;j++)
			{	s=s+a[j][i];
			}
			col=col+s;
			cout<<"\nSUM OF COLUMN "<<i+1<<" = "<<s;
			s=0;
		}
		cout<<"\nSUM OF LEFT DIAGONAL ="<<left;
		cout<<"\nSUM OF RIGHT DIAGONAL ="<<left;
		cout<<"\nSUM OF ROWS = "<<row;
		cout<<"\nSUM OF COLUMNS = "<<col;
		getche();
}