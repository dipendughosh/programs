//Sorting Array

#include <iostream.h>
#include <conio.h>

void display(int number[3][3])
{	for (int i = 0; i < 3; i++)
	{	for (int j = 0; j < 3; j++) cout<<number[i][j]<<"\t";
		cout<<endl;
	}
}

void arrang(int number[3][3],char rocol)
{	void sort(int&,int&);
	for (int i = 0; i < 3; i++)
	{	for (int j = 0; j < 3; j++)
			for (int k = 1; k < 3; k++)
			{	if (rocol=='r') sort(number[i][j],number[i][k]);
				else sort(number[j][i],number[j][k]);
			}
		}
}

void main()
{	int num[3][3] = { { 4,6,1 },{12,45,8},{5,8,3} };
	char rc;
	clrscr();
	display(num);
	getche();
	cout<<"\nArrange Rowwise/Coloumnwise (R/C) ?"; cin>>rc;
	arrang(num,rc);
	display(num);
	getche();
}

void sort(int& x,int& y)
{	int temp;
	temp = x; x = y; y = temp;
}

