#include<fstream.h>
#include<string.h>
#include<conio.h>

void main()
{	clrscr();
	const int len=80;
	char word[len];
	ifstream fin ("Frank.txt");
	while(fin)
	{	fin.getline(word,len);
		cout<<word;
	}
	fin.close();
	getche();
}































































































































