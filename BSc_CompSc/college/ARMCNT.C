//armstrong numbers till n
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       int i,s,a,n,b;
	clrscr();
	printf("Enter limit-");
	scanf("%d",&n);
	printf("Armstrong Numbers are-");
	for(i=1;i<n;i++)
	{	b=i;
		s=0;
		while(b>0)
		{	a=b%10;
			s=s+pow(a,3);
			b=b/10;
		}
		if(i==s)
			printf("\t\a%d",i);
	}
	getch();
}

