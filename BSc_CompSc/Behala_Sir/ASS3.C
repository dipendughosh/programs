#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       int n1,n2,a,b,a1=0,b1=0,x,y,s,i,j;
	clrscr();
	do
	{	printf("Enter Starting = ");
		scanf("%d",&n1);
		printf("Enter Ending = ");
		scanf("%d",&n2);
	}while(n1<9);
	x=n1;
	y=n2;
	while(n1>0)
	{	a=n1%10;
		n1=n1/10;
		a1++;
	}
	while(n2>0)
	{	b=n2%10;
		n2=n2/10;
		b1++;
	}
	for(i=a1;i<=b1;i++)
	{       for(j=x;j<=y;j++)
		{       if(j>=(pow(10,i) && j<pow(10,(i+1))))
			{       b=j;
				s=0;
				while(b>0)
				{	a=b%10;
					b=b/10;
					a=pow(a,i);
					s=s+a;
				}
				if(s==j)
					printf("%d\t",j);
			}
		}
	}


	getch();
}

