//GENERATE FIBONACCI SERIES OF PRIME NUMBERS FORM 1 TO 10000
#include<conio.h>
#include<iostream.h>

void main()
{	clrscr();
	int a=1,b=1,c,isprime(int);
	while(c<=1000)
	{	c=a+b;
		if (isprime(c))
			cout<<c<<"  ";
		a=b;
		b=c;
	};
	getch();
}

int isprime(int p)
{	int flag=0;
	for(int a=2;a<p;++a)
	{  if(p%a==0)
		 {	flag=1;
			break;
		 }
	}
	   if(flag==0)	  return 1;
	   else  return 0;
}