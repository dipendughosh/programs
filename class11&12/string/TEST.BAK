#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	char date[15];
	int i,len,a,t=1,s=0,dd[3],x=2;
	gets(date);
	len=strlen(date);
	for(i=(len-1);i>=-1;i--)
	{	a=date[i]-48;
		if(a>=0 && a<=9)
		{	s=s+(a*t);
			t*=10;
		}
		else
		{	dd[x]=s;
			s=0;
			t=1;
			--x;
		}
	}
	cout<<"\ndd "<<dd[0]<<" mm "<<dd[1]<<" yy "<<dd[2];

	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
