#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	char name[80],str[80];
	int i,j,x,len;
	cout<<"\nEnter name : ";
	gets(name);
	len=strlen(name);
	for(i=0;i<len;i++)
	{	if(name[i]!=' ' || name[i]!='\0')
		{	str[x]=name[i];
			x++;
		}
		if(name[i]==' ' && name[i+1]==' ')
		{	for(j=i+1;j<len;j++)
			{	str[x]=name[j+1];
				x++;
			}
		}
	}
	str[x]='\0';
	cout<<"\nName : ";
	puts(str);
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
