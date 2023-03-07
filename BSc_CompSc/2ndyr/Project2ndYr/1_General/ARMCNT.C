//armstrong numbers till n
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       int i,s,a,n1,n2,b;
	clrscr();
	printf("Enter lower limit-");
	scanf("%d",&n1);
	printf("Enter upper limit-");
	scanf("%d",&n2);
	if(n1<1)
		n1=1;
	printf("Armstrong Numbers are-");
	for(i=n1;i<n2;i++)
	{	b=i;
		s=0;
		while(b>0)
		{	a=b%10;
			s=s+pow(a,3);
			b=b/10;
		}
		if(i==s)
			printf("\t%d",i);
	}
	getch();
}

