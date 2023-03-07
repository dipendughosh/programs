//finding consequtive voeels
#include<stdio.h>

main()
{	FILE *fs,*ft;
	char c,c1;
	int i=0;
	fs=fopen("f1.txt","r");
	if(fs==NULL)
	{	printf("Cannot open source file");
		return;
	}
	ft=fopen("f2.txt","w");
	if(ft==NULL)
	{	printf("Cannot open target file");
		return;
	}
	c=fgetc(fs);
	while(c!=EOF)
	{	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
		{	c1=c;
			c=fgetc(fs);
			if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
			{	fputc(c,ft);
				fputc(c1,ft);
				i++;
			}
			else
			{	fputc(c1,ft);
				fputc(c,ft);
			}
		}
		else
			fputc(c,ft);
		c=fgetc(fs);
	}
	fclose(fs);
   fclose(ft);
	printf("number of times = %d",i);
	return;
}