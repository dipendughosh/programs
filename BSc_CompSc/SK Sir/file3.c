//Change the cases of all the vowels

#include<stdio.h>

main()
{	FILE *fs,*ft;
	char c;

	fs=fopen("f1.txt","r");
	if(fs==NULL)
	{	printf("Source file cannot be opened");
	}
	ft=fopen("f2.txt","w");
	if(ft==NULL)
	{	printf("Target file cannot be opened");
	}
	c=getc(fs);
	while(c!=EOF)
	{	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
			putc(c-32,ft);
		else if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
			putc(c+32,ft);
		else
			putc(c,ft);
		c=getc(fs);
	}
	fclose(fs);
	fclose(ft);
}
