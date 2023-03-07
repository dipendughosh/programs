//To convert a numerical string to its float value
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>

void main()
{       char str[10];
	float atof1(char []);
	clrscr();
	printf("\nEnter a numerical string :- ");
	gets(str);
	printf("\nThe floating value is :- %f",atof1(str));
	getch();
}

float atof1(char str[])
{       float a,b,c;
	int i,len,x,f,j;
	len=strlen(str);
	b=0;
	c=0;
	x=0;
	f=0;
	for(i=len-1;i>=0;i--)
	{	if(str[i]=='.')
		{	j=i;
			f=1;
			--i;
		}
		if(f==1)
		{	a=(str[i]-48)*(pow(10,x));
			c=c+a;
			x++;
		}
	}
	x=1;
	for(j=j+1;j<len;j++)
	{       {	a=(str[j]-48)/(pow(10,x));
			b=b+a;
		}
		x++;
	}
	a=c+b;
	return(a);
}