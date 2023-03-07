//Program to find the initial of a given name
//Input :-Amit Kumar Kar
//Output :- A.K.Kar
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
	for(i=0;i<=len;i++)
	{  /*if(name[i]=='\t')
			name[i]=' ';*/
		if(name[i]==' ' && name[i+1]==' ')
		{	for(j=i+1;j<=len;j++)
			{	name[j]=name[j+1];
			}
			len--;
			i--;
		}
	}
	for(i=0;i<len;i++)
	{	if(name[i]==' ')
			x++;
	}
	printf("The initial is:- %c.",name[0]);
	for(i=1;i<len;i++)
	{	if(name[i]==' ')
		{  /*     while(name[i+1]==' ')
			{	++i;
			}*/
			y++;
			if(y<x)
			{	printf("%c.",name[i+1]);
			}
			else
			{	for(j=i+1;j<len;j++)
					printf("%c",name[j]);

			}
		}
	}
	getche();
}
