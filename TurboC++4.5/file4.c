//Removing comment lines from a .c file
#include<stdio.h>
/*hhhh*/
main()
{	FILE *fp;
	char c1;
	fp=fopen("file3.c","r");
	if(fp==NULL)
	{	printf("Error in opening the file");
	}
	c1=fgetc(fp);
	while(c1!=EOF)
	{	if(c1 == '/')
		{  c1=fgetc(fp);
			if(c1 == '*')
			{  while(1)
				{	c1=fgetc(fp);
					if(c1 == '*')
					{	c1=fgetc(fp);
						if(c1 == '/')
							break;
					}
				}
			}
			else
			{	fseek(fp,-1,SEEK_CUR);
				printf("%c",c1);
				c1=fgetc(fp);
			}
		}
		else
		{	printf("%c",c1);
			c1=fgetc(fp);
		}
	}
	//printf("%c",c1);
	fclose(fp);
	return(0);
}

