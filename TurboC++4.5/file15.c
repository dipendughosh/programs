//1 blank by 2 blank and starting letter of each word in caps

#include<stdio.h>

main()
{	FILE *fs,*ft;
	char c;
	fs=fopen("f1.txt","r");
	if(fs==NULL)
	{	printf("Cannot open source file");
		return(0);
	}
	ft=fopen("f2.txt","w");
	if(ft==NULL)
	{	printf("Cannot open target file");
		return(0);
	}
	c=fgetc(fs);
	if(c>=97 && c<=122)
	{	fputc(c-32,ft);
		c=fgetc(fs);
	}
	while(c!=EOF)
	{	if(c=='.' || c=='\n' || c=='\0' || c=='?' || c==';' || c==',')
		{	fputc(c,ft);
			c=fgetc(fs);
			if(c=='\n')
				continue;
			if(c>=97 && c<=122)
				fputc(c-32,ft);
			else
				fputc(c,ft);
		}
		else if(c==' ')
		{	fputc(' ',ft);
			fputc(' ',ft);
			c=fgetc(fs);
			if(c>=97 && c<=122)
				fputc(c-32,ft);
			else
				fputc(c,ft);
		}
		else
			fputc(c,ft);
		c=fgetc(fs);
	}
	fclose(fs);
	fclose(ft);
	return(0);
}
