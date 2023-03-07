// Checking Sentence Palindrome
#include<iostream.h>
#include<conio.h>
#include<string.h>
//#include<iostream.h>
void main()
{	//clrscr();
	char sent[80],sent2[80];int len;
	char makeword(char[],char[],int);
	void checkpal(char*,int);
	cout<<"Enter a sentence : ";
    cin.getline(sent,80);
	makeword(sent,sent2,strlen(sent));
	cout<<"Sentence without spaces :"<<sent2;
	getche();
	checkpal(sent2,strlen(sent2));
	getche();
}

char makeword(char sntnce[],char sntnce2[],int ln)
{	int p =0 ,i=0;
	for ( i=0; i<=ln; i++)
	{	if (sntnce[i] != ' ') //continue;
		sntnce2[p++] = sntnce[i];
	}
               //cout<<"p"<<p<<"i"<<i;getche();
	return sntnce2[p-1];
}

void checkpal(char snt[],int leng)
{   int k,x;
    for (k=0,x=leng-1; k<leng-1; k++,x--)
    	{if(*(snt+k) != *(snt+x)) break;}
    if (k<leng-1) cout<<"\nSorry! NOT a Palindrome.";
	else cout<<"\nAha.. It IS a Palindrome.";
}
