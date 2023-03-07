#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       int s=0,a,b,d,i;
	clrscr();
	for(i =100;i<=500;i++)
	{   	b=i;s=0;
		while(b>=1)
		{	a=b%10;
			d=pow(a,3);
			s=s+d;
			b=b/10;
		}
		if(i==s)
			printf("%d\n",i);//cout<<i<<"\n";
	}

	getch();
}

