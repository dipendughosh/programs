#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{	clrscr();
	int a[21][21],i,j,input;
	cout<<"ENTER A NUMBER :";
	cin>>input;
	int n=input-1,row=0,col=n/2,ctr=1;
	for(i=0;i<input;i++)
		for(j=0;j<input;j++)
			a[i][j]=0;
	while(ctr<=input*input)
	{	a[row--][col++]=ctr++;
		if(row<0)
		{	if(col>n)
			{	row+=2;
				col--;
			}
			else
				row=n;
		}
		else
		{	if(col>n)
				col=0;
			else if(a[row][col]>0)
			{	row+=2;
				col--;
			}
		}
	};
	for(i=0;i<input;i++)
	{	for(j=0;j<input;j++)
		{	cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}