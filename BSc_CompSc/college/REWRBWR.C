//good morning- morning good
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

void main()
{       char str1[80],str2[80];
	int len,i,x,j,k;
	clrscr();
	printf("Enter a string - ");
	gets(str1);
	len=strlen(str1);
	x=0;
	k=len-1;
	for(i=len;i>=0;i--)
	{	if(str1[i]==' ' || i==0)
		{	for(j=i;j<=k;j++)
			{	str2[x]=str1[j];
				++x;
			}
			k=i;
			//str2[x]=' ';
		}
	}
	str2[x]='\0';
	puts(str2);

	getch();
}

