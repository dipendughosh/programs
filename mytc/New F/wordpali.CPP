#include<iostream.h>
#include<conio.h>
#include<string.h>

void main()
{	char line[80];//,pal='Y';
	clrscr();
	cout<<"Enter a line/word : "; cin>>line;
	int len=strlen(line);
	for(int l=0,i=0,r=len-1; i<len; i++,l++,r--)
		if(*(line+l) != *(line+r)) break;

	if(i==len) cout<<line<<" is a Pal";
	else cout<<line<<" is NOT a pal";
	getche();
}