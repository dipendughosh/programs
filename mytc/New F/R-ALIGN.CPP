//TO RIGHT ALIGN A STANZA OF POETRY
//dis does not work for more if len >78!!
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{	clrscr();
	char str[100];
	int i,j,p,l,len;
	cout<<" enter a poem ! \n(put $ sign when to break line )";
	gets(str);
	cout<<"\n your poem is :\n";
	l=strlen(str);
	for(i=0;i<l;i++)
	{
		if(str[i]=='$')
			cout<<endl;
		else
			cout<<str[i];
	}
	cout<<" right aligned poem :\n ";
	p=0;
	for(i=0;i<l;i++)
	{	if(str[i]=='$' )
		{	len=78-(i-p);
			while(len--)
				cout<<" ";
			for(j=p;j<i;j++)
				cout<<str[j];
			cout<<"\n ";
			p=i+1;
		 }
	 }
	 getche();
}

