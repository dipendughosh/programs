#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	char a[10][10];
	int j,x,n,i,y;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			a[i][j]=' ';
	cout<<"\nNumber of rows & columns ::";
	cin>>n;
	n;
	x=n%2;
	x--;
	y=x;
	for(i=0;i<n;i++)
	{	if(i==x)
		{	cout<<"*";
		}
		else
		{	cout<<a[0][i];
		}
	}
	cout<<"\n";
	for(i=1;i<n;i++)
	{	x--;
		y++;
		for(j=0;j<n;j++)
		{	if(j>=x && j<=y)
			{	cout<<"*";
			}
			else
			{	cout<<a[i][j];
			}
		}
		cout<<"\n";
	}
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}
/*#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

int main()
{	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
	return(0);
	
}*/
