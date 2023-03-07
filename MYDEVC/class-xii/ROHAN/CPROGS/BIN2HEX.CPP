//Binary to hexadecimal  **not via decimal**
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	int c[500],s=0,index=0,len=0,len1=0,p=0,n=0,count=0,pos,q=0;
	char a[500];
	clrscr();
	cout<<"\nEnter binary number..-->";gets(a);
	len=strlen(a);
	len1=(len/4)*4;
	p=len-len1;
	for(int j=len-1;j>=p;j-=4)
	{
		s=0;
		index=0;
		pos=j;
		for(int k=1;k<=4;k++)
		{
			n=(int)(a[pos])-48;
			s+=n*pow(2,index);
			index++;
			pos--;
		}
		c[count]=s;
		count++;
	}
	if(len1==len)
	{
		cout<<"\nHexadecimal number is..-->";
		for(int k=count-1;k>=0;k--)
		{
			if(c[k]<10)
				cout<<c[k];
			else
				cout<<(char)(c[k]+55);
		}

		getch();
		exit(0);
	}
	index=0;s=0;
	for(j=p-1;j>=0;j--)
	{
		q=(int)(a[j]);
		n=q-48;
		s+=n*pow(2,index);
		index++;
	}
	c[count]=s;
	cout<<"\nHexadecimal number is..-->";
	for(int k=count;k>=0;k--)
	{
		if(c[k]<10)
			cout<<c[k];
		else
			cout<<(char)(c[k]+55);
	}
	getch();
}
