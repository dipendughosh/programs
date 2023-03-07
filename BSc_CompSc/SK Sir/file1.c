//Reverse the letters of the words of the file

#include<stdio.h>


main()
{	FILE *fs,*ft;
	char stk[30],c;
	int tp;
	fs=fopen("f1.txt","r");
	if(fs==NULL)
	{	printf("Source file cannot be read");
	}
	ft=fopen("f2.txt","w");
	if(ft==NULL)
	{	printf("Destination file cannot be read");
	}
	tp==-1;
	c=getc(fs);
	while(c!=EOF)
	{	if(c==' ' || c=='\n' || c=='.' || c==',' || c==';' || c=='\t' || c=='?')
		{	while(tp!=-1)
				putc(stk[tp--],ft);
			putc(c,ft);
			c=getc(fs);
			continue;
		}	
		stk[++tp]=c;
		c=getc(fs);
	}
	fclose(fs);
	fclose(ft);
}
		
