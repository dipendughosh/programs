//amit kumar kar-a.k.kar
#include<string.h>
#include<conio.h>
#include<stdio.h>


void main()
{	int i,j,len,x=0,y=0;
	char name[80];
	clrscr();
	printf("Enter name ::");
	gets(name);
	len=strlen(name);
	for(i=0;i<len;i++)
	{	if(name[i]==' ')
			x++;
	}
	printf("%s.",name[0]);
	for(i=1;i<len;i++)
	{	if(name[i]==' ')
		{       while(name[i+1]==' ')
			{	++i;
			}
			y++;
			if(y<x)
			{	printf("%s.",name[i+1]);
			}
			else
			{	for(j=i+1;j<len;j++)
					printf("%s",name[j]);

			}
		}
	}
	getche();
}
