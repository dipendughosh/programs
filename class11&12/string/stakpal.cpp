#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>

void main()
{	clrscr();
	char arr[50],stack[50],inverse[50],flag=1;
	int index=0,top=-1,bot=0;
	cout<<"\nEnter word: ";
	gets(arr);
	while(arr[index]!='\0')
		stack[++top]=arr[index++];
	stack[++top]='\0';
	while(--top>=0)
		inverse[bot++]=stack[top];
	index=0;
	while(arr[index]!='\0')
	{	if(arr[index]!=inverse[index])
		{	flag=0;
			break;
		}
		index++;
	}
	if(flag==1)
		cout<<"\nPallindrome";
	else
		cout<<"\nSorry Not Pallindrome";

	getche();
}
