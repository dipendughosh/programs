//2 find d max no. of alph. in a sentence
//dos not work if  2 letters are same no of times
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>
void main()
{	clrscr();
	char s[20],l;
	int len,p=0,lar=0,x,large=0;
	cout<<"enter a sentence : "; gets(s);
	len=strlen(s);
	while(p<=len)
	{	x=s[p];
		for (int i=p;s[i]!='\0';i++)
			 if(s[i]==x) lar++;
		if(lar>large)
		{	large=lar;
			l=s[p];
		}
		lar=0;
		p++;
	};
	cout<<"\nLetter : "<<l;
	cout<<"\nNo. of times: "<<large;
	getche();
}