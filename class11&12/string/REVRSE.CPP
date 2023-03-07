//thank you
//knaht uoy
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	char str[80],str2[80];
	int len,i,j,k,x=0,y=0;
	cout<<"\nEnter a string : ";
	gets(str);
	len=strlen(str);
	str[len]=' ';
	k=0;
	for(i=0;i<=len;i++)
	{       if(str[i]==' ' || str[i]=='\0')
		{	y++;
			for(j=i-1;j>=k;j--)
			{	str2[x]=str[j];
				x++;
			}
			k=i;
			if(y==1)
			{	str2[x]=' ';
				x++;
			}
		}
	}
	str2[x]='\0';
	puts(str2);
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
