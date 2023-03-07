//prime till n
#include<stdio.h>
#include<conio.h>

void main()
{       int i,n,j,b,c,k,n1,n2,flag;
	clrscr();
	printf("Enter Lower limit - ");
	scanf("%d",&n1);
	printf("Enter Lower limit - ");
	scanf("%d",&n2);
	if(n1<2)
		n1=2;
	printf("\nPrime numbers are-");
	for(j=n1;j<=n2;j++)
	{       c=0;
		for(i=1;i<=(j/2);i++)
		{	b=j%i;
			if(b==0)
				++c;
		}
		if(c==1)
			printf("\t%d",j);

	}
	getch();
}

