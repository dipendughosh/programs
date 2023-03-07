// ********piglatin of each word*******//
# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
void main()
{   clrscr();
    char sen[1000],word[100],ch;
	int i,j,length = 0,l=0;
	void piglatin(int,char[100]);
	cout<<"\nEnter a sentence ";
	gets(sen);
    cout<<"\nThe ORIGINAL sentence is :\n";
	puts(sen);
	length = strlen(sen);
    for(i = 0;i<length;i++)
	{	ch = sen[i];
		if(ch == ' ')
		{   piglatin(l,word);
			l = 0;
		}
        else
        {     word[l] = ch;
		      l++;
        }
	}
	getche();
}
void piglatin(int len,char wrd[])
{   int i,j,p=0,flag = 0;
	char vowels[] ="aeiou",end[100];
	for(i = 0;i<len-1;i++)
	{   for(j = 0;j<5;j++)
		{   if(vowels[j] == wrd[i])
			{   for(int k = i;k<len;k++)
					cout<<wrd[k];
				flag = 1;
				break;
			}
		}
		end[p]=wrd[i];
		p++;
        if(flag == 1)
		{   for(int k=0;k<p-1;k++)
                cout<<end[k];
            cout<<"ay";
			break;
		}
	}
    cout<<" " ;
 }



