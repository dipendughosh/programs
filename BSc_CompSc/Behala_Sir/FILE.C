#include<stdio.h>
#include<conio.h>


void main()
{       FILE *fp;
	char ch[80],ch1;
	int i=0;
	clrscr();
	fp=fopen("c:\tst.c","w");
	printf("Enter name:-");
	gets(ch);
	while(ch[i]!='\0')
	{	fprintf(fp,"%c",ch[i]);
		i++;
	}
	fclose(fp);
	fp=fopen("c:\tst.c","r");
	i=0;
	while(!feof(fp))
	{	fscanf(fp,"%c",&ch1);
		printf("%c",ch1);
	}
	fclose(fp);
	getch();
}

