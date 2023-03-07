//number of lines,words,characters,ok
#include<stdio.h>
#include<string.h>

main(int a,char *b[])
{	FILE *fs;
	char ch;
	int l=0,w=0,c=0;
	if(strcmp(b[1],"-l")==0)
		fs=fopen(b[2],"r");
	else if(strcmp(b[1],"-w")==0)
		fs=fopen(b[2],"r");
	else if(strcmp(b[1],"-c")==0)
		fs=fopen(b[2],"r");
	else
		fs=fopen(b[1],"r");
	if(fs==NULL)
	{	printf("Cannot open Source file");
		return;
	}
	ch=fgetc(fs);
	while(ch!=EOF)
	{	if(ch==' ')
			w++;
		if(ch=='\n')
			l++;
		c++;
		ch=fgetc(fs);
	}
	if(strcmp(b[1],"-l")==0)
		printf("%d\n",l);
	else if(strcmp(b[1],"-w")==0)
		printf("%d\n",w);
	else if(strcmp(b[1],"-c")==0)
		printf("%d\n",c);
	else
		printf("%d\t%d\t%d",l,w,c);
	fclose(fs);
	return;

}

