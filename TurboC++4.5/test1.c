//test
#include<stdio.h>
#include"stk.h"

main()
{	int a,i;
	for(i=0;i<13;i++)
	{	printf("Enter data");
		scanf("%d",&a);
		push(a);
	}
	a=pop();
   printf("%d",a);
	return(0);
}
