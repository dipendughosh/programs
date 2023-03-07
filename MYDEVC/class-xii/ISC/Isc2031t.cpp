#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class text
{	private:
	char txt[200];
	int i,wi,wo,len,len2;
	public:
	text()
	{	wo=0;wi=0;
	}
	void readtext();
	char charat(int);
	int length();
	int noofwhitespaces();
	int noofwords();
	void display();
};

void text::readtext()
{	cout<<"\nEnter a string->\n";
	gets(txt);
}

char text::charat(int i)
{	cout<<txt[i];
	return(0);
}

int text::length()
{	len=strlen(txt);
	for(i=0;i<200;i++)
	{	if(txt[i]=='\0')
		{	len2++;
			break;
		}
		else
		{	len2++;
		}
	}
	return(0);
}

int text::noofwhitespaces()
{	for(i=0;i<len;i++)
	{	if(txt[i]==' ')
		{	wi++;
		}
	}
	return(0);
}

int text::noofwords()
{	for(i=0;i<len;i++)
	{	if(txt[i]>='a' || txt[i]<='z' || txt[i]>='A' || txt[i]<='Z')
			wo++;
	}
	if(wi==0)
		wo=1;
	else
		wo=wo-wi;
	return(0);
}

void text::display()
{	cout<<"\nText                  No of words   No of white spaces\n";
	cout<<txt<<"        "<<wo<<"   "<<wi;
}
void main()
{	clrscr();
	text obj;
	obj.readtext();
	obj.charat(3);
	obj.length();
	obj.noofwhitespaces();
	obj.noofwords();
	obj.display();
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

