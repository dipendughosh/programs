#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>

class format
{		char str[100];
		int len;
	public:
		format()
		{	len=0;
		}
		void readstring()
		{	cout<<"Enter the sentences with proper punctuations : \n";
			gets(str);
		}
		char charat(int index)
		{	return str[index];
		}
		void writechar()
		{	cout<<"\n";
		}
		int isupperc(char c)
		{	if (c>=65 && c<=90)
				return 1;
			else
				return 0;
		}
		int isendofsentence(int i)
		{   if (str[i]=='.')
			{	if (str[i+1]==' ')
				{	if ( isupperc(str[i+2]) )
						return 1;
					else return 0;
				}
				else return 0;
			}
			else return 0;
		}
		void formatstr()
		{   len=strlen(str);
			for(int a=0;a<len;a++)
			{   cout<<str[a];
				if ( isendofsentence(a) )
					writechar();
			}
		}

};

void main()
{   clrscr();
	format s;
	s.readstring();
	s.formatstr();
	getch();
}