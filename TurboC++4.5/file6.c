//only one blank space and upper to lower and vice versa,ok
#include<stdio.h>

main()
{	FILE *fs,*ft;
	char c;
	if((fs=fopen("f1.txt","r"))==NULL)
	{	printf("Cannot open source file");
		return;
	}
	if((ft=fopen("f2.txt","w"))==NULL)
	{	printf("Cannot open target file");
		return;
	}
	c=fgetc(fs);
	while(c!=EOF)
	{	if(c>='a' && c<='z')
			fputc(c-32,ft);
		else if(c>='A' && c<='Z')
			fputc(c+32,ft);
		else if(c==' ')
		{  c=fgetc(fs);
			if(c==' ')
			{	c=fgetc(fs);
				if(c!=' ')
					fputc(' ',ft);
				continue;
			}
			else if(c!=' ')
			{  fputc(' ',ft);
				continue;
			}
		}
		else
			fputc(c,ft);
		c=fgetc(fs);
	}
	fclose(fs);
	fclose(ft);
	return;
}


