#include<stdio.h>
#include<conio.h>

void main()
{       int x,i,j,f;
	clrscr();
	for(j=1;j<=300;j++)
	{       x=0;
		for(i=2;i<=j;i++)
		{	f=j%i;
			if(f==0)
				x++;
			if(x>1)
				break;
			else
				continue;
		}
		if(x==1)
			printf("%d ",j);
	}
	getch();
}

