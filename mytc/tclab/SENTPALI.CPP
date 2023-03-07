//chek 4 palindrome
#include<iostream.h>
#include<conio.h>
#include<string.h>
void main()
{	clrscr();
	char sent[80],sent2[80];int len;
	char makeword(char*,char*,int);
	void checkpal(char*,int);
	cout<<"Enter a sentence : "; cin.getline(sent,80);
	makeword(sent,sent2,strlen(sent));
	cout<<"Sentence without spaces :" <<sent2;
	getche();
	checkpal(sent2,strlen(sent2));
	getche();
}

char makeword(char sntnce[],char sntnce2[],int ln)
{	int p = 0;
	for (int i=0; i<ln; i++)
	{	if (sntnce[i] == ' ') continue;
		else
		{	sntnce2[p] = sntnce[i];
			p++;
		}
	}
	return sntnce2[p];
}

void checkpal(char snt[],int l)
{	for (int x=l-1,j=0; j<l; j++,x--)
		if(*(snt+j) != *(snt+x)) break;
	if (j<l-1) cout<<"\nSorry! NOT a Palindrome.";
	else cout<<"\nAha.. It IS a Palindrome.";
}