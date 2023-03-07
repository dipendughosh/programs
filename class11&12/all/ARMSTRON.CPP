														//*PROGRAM NO -5*
//*ARMSTRONG NUMBER*
#include<iostream.h>
#include<conio.h>
#include<math.h>

void main()
{ //	clrscr();
	int s=0,a,b,d;
	for(int i =100;i<=10000;i++)
	{   	b=i;s=0;
		while(b>=1)
		{	a=b%10;
			d=pow(a,3);
			s=s+d;
			b=b/10;
		}
		if(i==s)
			cout<<i<<"\n";
	}
	getche();
}