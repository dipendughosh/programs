//MULTIPLYING TWO 2D ARRAY'S
//MA SIZE OF ARRAY'S IS 10X10
#include<conio.h>
#include<iostream.h>
#include<process.h>
void main()
{
	clrscr();
	int a[10][10],b[10][10],c[10][10];
	int row1,row2,col1,col2,s=0;
	void prn(int[10][10],int,int);
	cout<<"\nEnter dimension's of array a().....";cin>>row1>>col1;
	cout<<"\nEnter dimension's of array b().....";cin>>row2>>col2;
	if(col1!=row2)
	{
		cout<<"\nCan't multiply......";
		exit(0);
	}
	cout<<"\nData for a().....\n\n";
	for(int i=0;i<row1;i++)
		for(int j=0;j<col1;j++)
		{
			cout<<"\nEnter data for cell...."<<"("<<i<<","<<j<<")";
			cin>>a[i][j];
		}
	 cout<<"\nData for b()....\n\n";
	 for(i=0;i<row2;i++)
		for(j=0;j<col2;j++)
		{
			cout<<"\nEnter data for cell...."<<"("<<i<<","<<j<<")";
			cin>>b[i][j];
		}
	 //c[row1][col2];

	 for(int x=0;x<row1;x++)
	 {
		for(int y=0;y<col2;y++)
		{
			for(int z=0;z<col1;z++)
			{
				s+=a[x][z]*b[z][y];
			}
			c[x][y]=s;
			s=0;
		}
	 }
	 clrscr();
	 cout<<"\n\nOUTPUT   :-  \n\n";
	 cout<<"\nARRAY a()....\n";
	 prn(a,row1,col1);
	 cout<<"\nARRAY b()....\n";
	 prn(b,row2,col2);
	 cout<<"\nPRODUCT ARRAY c()....\n";
	 prn(c,row1,col2);
	 getch();
}
void prn(int x[10][10],int row,int col)
{
	 for(int i=0;i<row;i++)
	 {
		for(int j=0;j<col;j++)
		{
			cout<<x[i][j]<<"\t";
		}
		cout<<endl;
	 }
}




