//incomplete
#include<iostream.h>
#include<conio.h>
#include<string.h>
void main()
{	clrscr();
	char sent[80],sent2[80];int len;
	cout<<"Enter a sentence : "; cin.getline(sent,80);
	int p = 0;
	for (int i=0; i<strlen(sent); i++)
	{	if (sent[i] == ' ') continue;
		else
		{	sent2[p] = sent[i];
			p++;
		}
	}
	cout<<sent2;
	len = strlen(sent2);
	for (int x=len-1,j=0; j<len; j++,x--)
		if(*(sent2+j) != *(sent2+x)) break;
	if (j<len-1) cout<<"\nSorry! NOT a Palindrome.";
	else cout<<"\nAha.. It IS a Palindrome.";
	getche();
}
