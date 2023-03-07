#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
void main()
{	clrscr();
	char mainstr[80],substr[80];
	int count,pos,i,j,len,num,x1;
	cout<<"\nENTER THE MAIN STRING \n";
	gets(mainstr);
	len =strlen(mainstr);
	cout<<"\nENTER STARTING POSITION OF SUB STRING\n ";
	cin>>pos;
	if(pos>len)
	{	cout<<"\nSTARTING POSITION EXCEEDS THE TOTAL "
		    <<"LENGTH OF THE STRING !!!!!!";
		    exit(0);
	}
	cout<<"\nTHE NUMBER OF CHARACTERS IN SUB STRING?\n";
	cin>>count;
	if(pos<=0)
	{	cout<<"\n\nEXTRACTED STRING IS EMPTY\n!!!!!!";
		exit(0);
	}
	else if(((pos+count)-1)>len)
	{	cout<<"\n\nSTRING TO BE EXTRACTED EXCEEDS LENGTH \n";
		num=len-pos;
	}
	else
	{	num=count;
		cout<<"\nNUM"<<num;
	}
	j=0;
	for(i=--pos;i<=(pos+num);i++)
	{	substr[j]=mainstr[i];
		j++;
	}
	cout<<"\nSUB STRING IS\n";
	puts(substr);
	getche();
}