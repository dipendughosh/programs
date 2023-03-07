#include<conio.h>
#include<iostream.h>

void main()
{   clrscr();
	int prod1=1,prod2=1;
	int reverse(int);
	cout<<"\n";
	for(int i=10;i<100;i++)
	{   if(reverse(i)==i) continue;
		for(int j=10;j<100;j++)
		{   if(reverse(j)==j) continue;
			if(i==j) continue;
			if(reverse(i)==j)  continue;
			prod1=i*j;
			prod2=(reverse(i)*reverse(j));
			if(prod1==prod2)
			cout<<i<<"\t"<<j<<"\tprod1:"<<prod1<<"\tprod2:"<<prod2<<"\n";
		}
	}
	getch();
}


int reverse(int p)
{   int rem,sumrem=0;
	rem=p%10;
	sumrem+=(rem*10);
	p=(p-rem)/10;
	sumrem+=p;
	return sumrem;
}