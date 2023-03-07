#include<stdio.h>
#include<conio.h>

void main()
{       char str[20];
	int i,len;
	clrscr();
	printf("Enter a String->");
	gets(str);
	len=strlen(str);
	for(i=0;i<=len;i++)
	{	if(str[i]>=97 && str[i]<=121)
			str[i]=str[i]-32;
	}
	printf("\n");
	puts(str);
	getch();
}

