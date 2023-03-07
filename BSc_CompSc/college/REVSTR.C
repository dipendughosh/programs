//dipendu-udnepid
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

void main()
{       char str[80];
	int len,i;
	clrscr();
	printf("Enter a string - ");
	gets(str);
	len=strlen(str);
	for(i=len-1;i>=0;i--)
		printf("%c",str[i]);
	getch();
}

