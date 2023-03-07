#include <iostream.h>
#include <conio.h>
#include<string.h>
#include<stdio.h>
void main()
{
	//clrscr();
	char sen[1000],vowels[]="aeiou",alpbet;
	int  i,j,vowel=0,k=1,length;
	cout<<"\nInput a sentence \n";
	gets(sen);
	cout<<"\nThe original sentence is \n";
	puts(sen);
	length = strlen(sen);
	for(i = 0;i<length;i++)
	{
		alpbet = sen[i];
		if(alpbet == ' ')
		{
			cout<<"\nin word number "<<k<<" there are "
				<<vowel<<"  vowels \n";
			k++;
			vowel = 0;
		}
		for(j = 0;j<5;j++)
		{
			if(alpbet == vowels[j])
				vowel++;

		}
	}
	i = length-1;
	vowel = 0;
	while(alpbet!=' ')
	{
		alpbet = sen[i];
		for(j = 0;j<5;j++)
		{
			if(alpbet == vowels[j])
				vowel++;

		}
		i--;
	}
	cout<<"\nin word number "<<k<<" there are "
				<<vowel<<" vowels \n";
	getche();
}





