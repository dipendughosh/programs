//test comand line argument

#include<stdio.h>
#include<string.h>

main(int a,char *b[])
{  int i;
	char str[80];
	for(i=0;i<a;i++)
	{	printf("%d\t",i);
		strcpy(str,b[i]);
		if(strcmp(str,"-l")==0)
			printf("\ny\n");
		puts(b[i]);
	}
	return(0);
}
