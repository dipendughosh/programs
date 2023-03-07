//pallindrome character
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>

void main()
{       char str1[80],str2[80];
	int len,i,x=0;
	clrscr();
	printf("Enter a string - ");
	gets(str1);
	len=strlen(str1);
	for(i=len-1;i>=0;i--)
	{	str2[x]=str1[i];
		x++;
	}
	str2[x]=str1[len];
	if(!(strcmp(str1,str2)))
		printf("\nPallindrome");
	else
		printf("\nNot Pallindrome");
	getch();
}

