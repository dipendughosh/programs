//merge alternatingly,ok
#include<stdio.h>

main()
{	FILE *fs1,*fs2,*ft;
	char c1,c2;
   int f;
	if((fs1=fopen("f1.txt","r"))==NULL)
	{	printf("Cannot open source file 1");
		return;
	}
	if((fs2=fopen("f2.txt","r"))==NULL)
	{	printf("Cannot open source file 2");
		return;
	}
	if((ft=fopen("f3.txt","w"))==NULL)
	{	printf("Cannot open target file");
		return;
	}
	c1=fgetc(fs1);
	c2=fgetc(fs2);
	f=1;
	while((c1!=EOF) & (c2!=EOF))
	{	if(f==1)
		{	fputc(c1,ft);
			if(c1=='\n')
				f=2;
			c1=fgetc(fs1);
		}
		else if(f==2)
		{	fputc(c2,ft);
			if(c2=='\n')
				f=1;
			c2=fgetc(fs2);
		}
	}
	if(c1!=EOF)
	{	while(c1!=EOF)
		{	fputc(c1,ft);
			c1=fgetc(fs1);
		}
	}
	if(c2!=EOF)
	{	while(c2!=EOF)
		{	fputc(c2,ft);
			c2=fgetc(fs2);
		}
	}
	fclose(fs1);
	fclose(fs2);
	fclose(ft);
	return;
}


