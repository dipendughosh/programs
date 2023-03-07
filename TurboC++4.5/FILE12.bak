//Replace a string by another string,ok
#include<stdio.h>
#include<string.h>

main()
{	FILE *fs,*ft;
	char c,str1[80],str2[80],str3[80];
	int a=0;
	fs=fopen("f1.txt","r");
	if(fs==NULL)
	{	printf("Cannot open source file");
		return;
	}
	ft=fopen("f5.txt","w");
	if(ft==NULL)
	{	printf("Cannot open target file");
		return;
	}
	printf("\nEnter string to replace-");
	gets(str1);
	printf("\nEnter string to replace with-");
	gets(str2);
	c=fgetc(fs);
	while(c!=EOF)
	{	if(c==' ' || c==',' || c==';' || c=='\n' || c=='\0' || c=='?' || c=='.')
		{  fputc(c,ft);
			str3[a]='\0';
			if(strcmp(str1,str3)==0)
				fputs(str2,ft);
			else
				fputs(str3,ft);
			a=0;
		}
		else
			str3[a++]=c;
		c=fgetc(fs);
	}
	str3[a]='\0';
	if(strcmp(str1,str3)==0)
		fputs(str2,ft);
	else
		fputs(str3,ft);
	fclose(fs);
	fclose(ft);
	return;
}
