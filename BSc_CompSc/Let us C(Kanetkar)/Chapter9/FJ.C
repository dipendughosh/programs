#include<stdio.h>
#include<conio.h>

void main()
{       char str[40];
	int len,i;
	clrscr();
	printf("Enter string-> ");
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{	if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
		{	if(str[i+1]=='a' || str[i+1]=='e' || str[i+1]=='i' || str[i+1]=='o' || str[i+1]=='u')
			{	printf("\n%c%c",str[i],str[i+1]);
			}
		}
	}
	getch();
}

