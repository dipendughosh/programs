#include<stdio.h>
#include<conio.h>

void main()
{       char str[80];
	int len,i,j;
	clrscr();
	printf("Enter a String-> ");
	gets(str);
	len=strlen(str);
	for(i=0;i<=len;i++)
	{	if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='u' || str[i]=='o')
		{	for(j=i;j<=len;j++)
				str[j]=str[j+1];
			i--;
		}
	}
	puts(str);
	getch();
}

