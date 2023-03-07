//class 11 3rd term Q.8
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	char str[80];
	int len,i,k=0,x=0,y=0,j,arr[40];
	for(i=0;i<40;i++)
		arr[i]=0;
	cout<<"Enter a string : ";
	gets(str);
	len=strlen(str);
	for(i=k;i<=len;i++)
	{	if(str[i]!=' ' || str[i]!='\0')
		{	x++;
		}
		if(str[i]==' ' || str[i]=='\0')
		{	arr[x-1]++;
			x=0;
			k=i+1;
			y++;
		}
	}
	for(i=1;i<y;i++)
	{	cout<<"\n"<<i<<"\t";
		for(j=0;j<arr[i];j++)
		{	cout<<"*\t";
		}
		cout<<"\n";
	}
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
