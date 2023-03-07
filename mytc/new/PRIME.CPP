#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	int i,j;
	for( i=1;i<=2;i++)
	{   int n = 0;
		for( j=2;j<i;j++)
		{	if(i%j==0)
			{	n = 1;
				break;
			}
		}
		if(n==0)
			cout<<"Prime "<<i<<endl;
	}
	getche();
}