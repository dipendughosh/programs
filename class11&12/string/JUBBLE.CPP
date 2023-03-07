#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
void main()
{	clrscr();
	char string1[8]="TROUBLE";
	char string2[8]="BLUEROT";
	int i,j,x=0;
	for(i=0;i<8;i++)
	{	for(j=0;j<8;j++)
		{	if(string1[i]==string2[j])
				++x;
		}
	}
	if(x==8)
		cout<<string1<<" is a jumble of "<<string2;
	else
		cout<<string1<<" is not a jumble of "<<string2;
	getche();
}