#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	clrscr();
	char sen[1000], alpbet;
	int  alpha=0,words=0,length,i,num=0,sign = 0;
	cout<<"input a sentence ";
	gets(sen);
	cout<<"\nThe original sentence is \n";
	puts(sen);
	length = strlen(sen);
	for(i = 0;i<length;i++)
	{
		alpbet = sen[i];
		if(isalpha(alpbet))
			alpha++;
		if(isdigit(alpbet))
			num++;
		if(alpbet ==' ')
			words++;
	}
	words++;
	cout<<"\n number of alphabets in the sentence is "<<alpha;
	cout<<"\n number of words in the sentence is "<<words;
	cout<<"\n number of numericals in the sentence is "<<num;
	cout<<"\n number of signs in the sentence is "<<sign;
	getche();
}



