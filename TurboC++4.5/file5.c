//Removing comment lines from a .c file,ok
#include<stdio.h>
/*hhhh*/
main()
{	FILE *fp;
	char c1,c2;
	fp=fopen("file3.c","r");
	if(fp==NULL)
	{	printf("Error in opening the file");
	}
	c1=fgetc(fp);
	c2=fgetc(fp);
	while(c2!=EOF)
	{	if(c1 == '/' && c2 == '*')
		{  c1=c2;
			c2=fgetc(fp);
			do
			{	c1=c2;
				c2=fgetc(fp);
			}while(c1 != '*' && c2 != '/');
		        c1=c2;
			c2=fgetc(fp);
			c1=c2;
			c2=fgetc(fp);
         continue;
		}
		printf("%c",c1);
      		c1=c2;
		c2=fgetc(fp);
	}
	/*5565656*/
	printf("%c",c1);
	return(0);
}

