//merge two int arrays into a single array in ascending order
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{	clrscr();
	int a[5]={1,3,5,9,11};
	int b[4]={3,6,7,13};
	int c[10],i,j,x,y,p=5,q=4,temp;
	for(y=0;y<5;y++)
		c[y]=a[y];
	for(i=0;i<q;i++)
	{	for (j=0;j<p;j++)
		{	if (c[j]>b[i])
			{	temp=c[j];  p++;
				for(x=p;c[x]!=temp;x--)
					c[x]=c[x-1];
				c[x]=b[i];
				continue;
			}
		}
	}
	cout<<"\nArray c : "<<endl;
	for(y=0;y<9;y++)
		cout<<c[y]<<"  ";
	getch();
}