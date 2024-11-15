//Assignment5

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class assignment5
{
	private:
		int noLine;
		int noBlnkLine;
		int noHlfLine;
		int noMltplLine;
		ifstream fin;
		//ofstream fout;
	public:
		assignment5()
		{
			noLine = 0;
			noBlnkLine = 0;
			noHlfLine = 0;
			noMltplLine = 0;
		}
	
		void openFiles();
		void readwrite();
		void closeFiles();
		void displayResult();
		//void noMltplLines(char []);
		
		~assignment5()
		{
		}
};

void assignment5::openFiles()
{
	fin.open("C:\\files\\PPMBtoPPMA.cpp",ios::in);
	//fout.open("C:\\files\\PPMBtoPPMA2.cpp",ios::out);
}

void assignment5::readwrite()
{
	int len = 0;
	
	char str[200];
	
	cout<<"Start\n";
	
	while(fin)
	{
		fin.getline(str,200);
		noLine++;
		len=strlen(str);
		if(len == 0)
			noBlnkLine++;
		noMltplLines(str);
		//fout<<len<<" :- "<<str<<"\n";
	}
			
	cout<<"Finish\n";
}

void assignment5::closeFiles()
{
	fin.close();
	//fout.close();
}

void assignment5::displayResult()
{
	cout<<"\nNumber of Lines = "<<noLine;
	cout<<"\nNumber of Blank Lines = "<<noBlnkLine;
	cout<<"\nNumber of Half Lines = "<<noHlfLine;
	cout<<"\nNumber of Multiple Lines = "<<noMltplLine;
}

void main()
{
	assignment5 ob;
	ob.openFiles();
	ob.readwrite();
	ob.closeFiles();
	ob.displayResult();
	cout<<"\n\n\n";
}

#include "aaa.h"

aaa::aaa()
{
}

aaa::~aaa()
{
}
