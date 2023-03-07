#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
int pal(int x)
{
	int h,s=0;
	while(x!=0)
	{
		h=x%10;
		x=x/10;
		s=s*10 + h;
	}
	return s;
}
int chk(int a,int b)
{
	int f=1;
	if(pal(a)==a && pal(b)==b)
		f=0;
	return f;
}
void main()
{
	clrscr();
	for(int i=11;i<99;i++)
	{       for(int j=i+1;j<100;j++)
		{       if(((i*j)==(pal(i)*pal(j)))&& chk(i,j)==1)
			{       cout<<"\n "<<i<<" x "<<j<<" = "<<pal(i)<<" x "<<pal(j);
				getch();
			}
		}
	}
	getch();
}
