//SUDOKU(JANUARY 2006)
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>

int R[10][10]={{0,0,0,0,0,0,0,0,0,0},
	       {0,0,0,6,0,0,1,3,0,0},
	       {0,0,0,0,0,9,0,6,1,0},
	       {0,8,0,3,0,0,0,5,0,4},
	       {0,0,7,0,0,1,2,0,6,0},
	       {0,0,0,0,0,5,0,0,0,0},
	       {0,0,6,0,7,3,0,0,5,0},
	       {0,3,0,1,0,0,0,8,0,6},
	       {0,0,4,5,0,2,0,0,0,0},
	       {0,0,0,7,6,0,0,1,0,0}};

void Union(int x[10],int y[10])
{	int i;
	for(i=1;i<10;i++)
		x[y[i]]=y[i];
}

void complement(int x[10],int y[10])
{       int i;
	for(i=1;i<10;i++)
		y[i]=i;
	for(i=1;i<10;i++)
		y[x[i]]=0;
}

void getRowset(int i,int x[10])
{	int j;
	for(j=1;j<10;j++)
		x[j]=0;
	for(j=1;j<10;j++)
		x[R[i][j]]=R[i][j];
}

void getCloset(int j,int x[10])
{	int i;
	for(i=1;i<10;i++)
		x[i]=0;
	for(i=1;i<10;i++)
		x[R[i][j]]=R[i][j];
}

void getBoxset(int i,int j,int x[10])
{       int r,c,k,m,n;
	for(m=1;m<10;m++)
		x[m]=0;
	k=1+3*((i-1)/3)+(j-1)/3;
	r=1+3*((k-1)/3);
	c=1+3*((k-1)%3);
	for(m=r;m<r+3;m++)
		for(n=c;n<c+3;n++)
			x[R[m][n]]=R[m][n];
}

int count(int x[10])
{	int i,cnt=0;
	for(i=1;i<10;i++)
		if(x[i]==i)
			cnt++;
	return cnt;
}

int getd(int x[10])
{       int i;
	for(i=1;i<10;i++)
		if(x[i]==i)
			break;
	return i;
}

void dispd(int i,int j,int p)
{	textcolor(12);
	gotoxy(10+4*j,i+6);
	cprintf("%d",p);
}

int dispgrid()
{	int i,j,nbc=0;
	textcolor(11);
	for(i=1;i<10;i++)
	{	for(j=1;j<10;j++)
		{	if(R[i][j]==0)
				nbc++;
			gotoxy(10+4*j,i+6);
			cprintf("%d",R[i][j]);
		}
	}
	return nbc;
}

int PASS()
{	int T[10],U[10],F[10][10][10];
	int i,j,k,d,n,r,c,nfc=0;
	for(i=1;i<10;i++)
	{	for(j=1;j<10;j++)
		{	if(R[i][j]!=0)
				continue;
			getRowset(i,T);
			getCloset(j,U);
			Union(T,U);
			getBoxset(i,j,U);
			Union(T,U);
			complement(T,F[i][j]);
			n=count(F[i][j]);
			if(n==0)
			{	printf("error");
				exit(0);
			}
			if(n==1)
			{	d=getd(F[i][j]);
				R[i][j]=d;
				nfc++;
				dispd(i,j,d);
			}
		}
	}
	return nfc;
}

void main()
{	int npass,nfc,nbc;
	clrscr();
	nbc=dispgrid();
	textcolor(15);
	gotoxy(20,2);
	cprintf("SUDOKU PUZZLE");
	gotoxy(10,20);
	cprintf("Number of blank cells = %d",nbc);
	gotoxy(10,21);
	cprintf("Press any key to continue......");
	getch();
	npass=0;
	do
	{	nfc=PASS();
		npass++;
		textcolor(15);
		gotoxy(10,4);
		cprintf("RESULTS");
		gotoxy(10,18);
		cprintf("Pass Number = %d",npass);
		gotoxy(10,19);
		cprintf("Number of cells filled in this pass = %d ",nfc);
		nbc=nbc-nfc;
		gotoxy(10,20);
		cprintf("Number of blank cells remaining = %d",nbc);
		if(nbc==0)
			break;
		getch();
	}while(nfc>0);
	if(nbc==0)
	{	gotoxy(10,21);
		cprintf("PUZZLE SOLVED!         ");
		getch();
	}
	else
	{	gotoxy(10,22);
		cprintf("The puzzle cannot be solved!         ");
		getch();
	}
	getche();
}

































































































































