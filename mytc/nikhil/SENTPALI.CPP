#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{	clrscr();
	int palindrome(char []);
	char s[51],n[51];
	int a=0,i=0,c;
	cout<<"Enter a sentence : ";  gets(s);
	int len=strlen(s);
	for(;i<len;i++)
	{	if(s[i]==' ') /*i++;*/continue;
		else n[a++]=s[i];
	}
	n[a]='\0';
	clrscr();
	puts(n);
	cout<<endl;
	c=palindrome(n);
	if(c==1) cout<<"\nThe sentence is a palindrome .";
	else cout<<"\nThe sentence is not a palindrome .";
	getch();
}


/*int palindrome(char sen[])
{   int len,flag=0;
	len=strlen(sen);
	for(int k=0;k<len;k++)
	{	for(int l=len-1;l>=0;l--)
		{   if(sen[k]==sen[l]) flag=1;
			else {flag=0;break;}
		}
	}
	return flag;
}*/
int palindrome(char sen[])
{   char sent[51];
	int len2=strlen(sen);
	int l=0,flag=0;
	for(int k=(len2-1);k>=0;k--) sent[l++]=sen[k];
	sent[l]='\0';
	for(int q=0;q<len2;q++)
	{	if(sen[q]!=sent[q])  {flag=0;break;}
		else flag=1;
	}
	return flag;
}