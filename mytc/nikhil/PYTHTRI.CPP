//PYTHAGOREAN TRIPLET
#include<conio.h>
#include<math.h>
#include<iostream.h>

double ret(int p,int q);

void main()
{   clrscr();
	int ver(double p);
	double b;
	int z;
	for (int i=1; i<=99; i++ )
	{	for (int j=i+1; j<100; j++ )
		{   b=ret(i,j);
			z=ver(b);
			if (z!=0) cout<<"i : "<<i<<"  j : "<<j<<"  k : "<<z;
//			else cout<<z;
			cout<<endl;
		   //	getch();
		}
	}
	getch();
}

double ret(int p,int q)
{/*   cout<<"\nIN FUNCTION RET()"<<endl;
	cout<<(p*p+q*q);*/
	return (p*p+q*q);
}

int ver(double p)
{	for(int x=1;x<=99;x++)
	{   if (x*x==p)
		{//   cout<<"\nx : "<<x;
			return x;
		}
//		else return  0;
	}
	return 0;
}