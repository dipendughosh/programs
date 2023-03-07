#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{	char str[50];
	clrscr();
	cout<<"Enter a name : ";
	gets(str);
   //int s = strlen(str);
	int i = 0,nn=0;
	while(str[i] != NULL)
	{
		cout<<str[i++];
		nn++;
	}
	//puts(str);
	cout<<"\nNo. of characters : "<<nn;
	getche();
}

