#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
void main()
{	clrscr();
	char string[80];
	int len,i=0,a=0,b=0,c=0,s=0,x=0;
	cout<<"ENTER A HEXADECIMAL NUMBER ";
	gets(string);
	len=strlen(string);
	for(i=(len-1);i>=0;i--)
	{	a=string[i];
		if(a>=48 && a<=58)
		{	b=a-48;
			c=(pow(16,x))*b;
			s=s+c;
		}
		if(a>=65 && a<=70)
		{       b=a-55;
			c=(pow(16,x))*b;
			s=s+c;
		}
		if(a>=97 && a<=103)
		{	b=a-87;
			c=(pow(16,x))*b;
			s=s+c;
		}
		x++;
	}
	cout<<"\nDECIMAL NUMBER IS "<<s;
	getche();
}