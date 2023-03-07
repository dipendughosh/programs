//*armstrong numbers *
#include<iostream.h>
#include<conio.h>
void main()
{	int i=2,j,r=0,x;
	clrscr();
	while(i<=50)
	{	x=1;
		for(j=2;j<=(i/2);j++)
		{	if(i%j==0)
			{	x=0;
				break;
			}
		}
		if(x==1)
		{	cout<<"\n"<<i;
			r++;
		}
		i++;
	}
	cout<<"\nthere are "<<r<<"  prime numbers";
	getche();
}
