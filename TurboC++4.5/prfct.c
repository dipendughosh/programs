//perfect no
#include<stdio.h>

main()
{	int n,i,s=0;
	for(n=1;n<=1000;n++)
	{  s=0;
		for(i=1;i<=n/2;i++)
		{	if((n%i)==0)
				s=s+i;
		}
		if(s==n)
		{	printf("\n%d yes",n);
			for(i=1;i<=n/2;i++)
			{	if((n%i)==0)
					printf("%d ",i);
			}
		}
	}
	return(0);
}