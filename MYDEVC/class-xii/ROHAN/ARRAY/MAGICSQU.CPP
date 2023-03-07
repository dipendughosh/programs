#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int a[7][7]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	void wait();
	int row=0,col=3,no=1;
	cout<<"\nMagic Square of a 7x7 matrix is.......\n\n\n";
	while(no<=49)
	{
		a[row][col]=no;
		no++;
		row--;
		col++;
		if(row<0)
		{
			if(col>6)
			{
				row+=2;
				col--;
			}
			else
				row=6;
		}
		else
		{
			if(col>6)
				col=0;
		}
		if(a[row][col]!=0)
		{
			row+=2;
			col--;
		}
	}
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			wait();
			cout<<"\t"<<a[i][j];
		}
		cout<<char(7)<<char(7);
		wait();
		cout<<endl<<endl;
	}
	cout<<char(7)<<char(7)<<char(7)<<char(7)<<char(7)<<char(7);
	wait();
	getche();
}
void wait()
{
	for(long i=0;i<1000;i++)
		for(long j=0;j<100;j++);     //	cout<<"i->"<<i<<"j->"<<j;

}