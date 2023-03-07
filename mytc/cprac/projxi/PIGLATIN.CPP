#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
	char sen[100],word[100],alpbet;
	int i,j,length,l = 0;
	void piglatin(int,char[100]);
	cout << "\nEnter a Sentence ";
	gets(sen);
	cout << "The original Sentence is \n";
	puts(sen);
	length = strlen(sen);
	for(i = 0; i<length; i++)
	{   alpbet = sen[i];
		word[l] = alpbet;
		if(alpbet == ' ')
		{   word[l]='\0';
			piglatin(l,word);
			l = 0;
		}
		l++;
	}
    getche();
    cout<<endl;
}
void piglatin(int lngth,char w[])
{	int i,j,flag = 0;
	puts(w);
    cout<<"\nlen="<<lngth;
	getche();
	char vowels[] = "aeiou";
	for(i = 0; i < lngth; i++)
	{	for(j = 0; j<5; j++)
		{	if(w[i] == vowels[j])
			{	cout<<w[i];
				for(int k = i; k < lngth; k++)
					cout<<w[k];
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{ 	for(int k = 0; k < i; k++)
				cout<<w[k];
			cout<<"ay";
			cout<<' ';
			break;
		}
	}
}
