//file name,line number:line,ok
#include<stdio.h>

main(int a,char *b[])
{	FILE *fs;
	char c;
	int i=0;
	if((fs=fopen(b[1],"r"))==NULL)
	{	printf("Cannot open Source File");
		return;
	}
	c=fgetc(fs);
	printf("%s,%d : ",b[1],i++);
	while(c!=EOF)
	{	if(c!='\n')
			printf("%c",c);
		else
			printf("\n%s,%d : ",b[1],i++);
		c=fgetc(fs);
	}
   fclose(fs);


}

