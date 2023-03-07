//******how many words are palindrome ?******//
# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
void main()
{
//	clrscr();
	char sen[1000],word[100],ch;
	int palindrome(int,char[100]);
	int i,j,length = 0,l=0,num = 0;
	cout<<"\nEnter a sentence ";
	gets(sen);
	cout<<"\nThe ORIGINAL sentence is :\n";
	puts(sen);
	length = strlen(sen);
	for(i = 0;i<length;i++)
	{
    	ch = sen[i];
		if(ch == ' ')
		{
			if(palindrome(l-1,word) == 1)
				num++;
			l = 0;
		}
		else
        {
            word[l] = ch;
            l++;
        }
	}
	cout<<"\nThere are "<<num<<"  palindromes in the sentence ";
	getche();
}
int palindrome(int len,char wrd[])
{
	int i=0,j=len,half,flag = 0;
	half = (len/2);
	while(i<half)
	{
		if(wrd[i]!=wrd[j])
		{
			flag = 1;
			break;
		}
		i++;
		j--;
	}
	if(flag == 1)
		return 0;
	return 1;
}		
	

