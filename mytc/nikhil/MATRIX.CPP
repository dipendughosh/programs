#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void add();
void main()
{	clrscr();
	int c;
	cout<<"Menu";
	cout<<"\n\n1.Addition of two matrices.\n\n";
	cout<<"2.Subtraction of two matrices.\n\n";
	cout<<"3.Multiplication o two matrices.\n\n";
	cout<<"Enter your choice : ";  cin>>c;
	clrscr();
	switch(c)
	{	case 1:add();break;
//		case 2:sub();break;
//		case 3:
	}
	getch();
}



void add()
{   int mat1[2][2],mat2[2][2],mat3[2][2];
	int a=0,b=0,i=0,j=0,m=0,n=0,x=0,y=0;
	int r1=2,r2=2,r3=6,c1=5,c2=15,c3=5;
	cout<<"Enter two 2*2 matrices(8 elements) : \n";
	for (;i<2;i++)  for(;j<2;j++)  cin>>mat1[i][j];
	for (;m<2;m++)  for(;n<2;n++)  cin>>mat2[m][n];
	clrscr();
	for (;a<2;a++)  for(;b<2;b++)  mat3[a][b]=mat1[a][b]+mat2[a][b];
	for (;x<2;x++)
	{	for(;y<2;y++)
		{	gotoxy(r1++,c1++); cout<<mat1[x][y];
			gotoxy(r2++,c2++); cout<<mat2[x][y];
			gotoxy(r3++,c3++); cout<<mat3[x][y];
		}
	}
}