#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int x,y,z,n=1,i;
	cout<<" enter three numbers ";
	cin>>x;
	cin>>y;
	cin>>z;
	i=z;
	while(n!=0)
	{
		if(i%x == 0)
		{
			if(i%y == 0)
			{
				if(i%z == 0)
				{
					n =0;
					break;
				}
			}
		}
		i++;
	}
	cout<<i<<"  is the l.c.m ";
	getche();
}
