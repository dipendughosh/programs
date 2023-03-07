//c++ file testing

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class test
{
	private:
		ifstream fin;
		ofstream fout;
	public:
		test()
		{
		}
	
		void openFiles();
		void readwrite();
		void closeFiles();
		
		~test()
		{
		}
};

void test::openFiles()
{
	fin.open("C:\\files\\PPMBtoPPMA.cpp",ios::in);
	fout.open("C:\\files\\PPMBtoPPMA2.cpp",ios::out);
}

void test::readwrite()
{
	int len = 0;
	char str[200];
	
	cout<<"Start\n";
	while(fin)
	{
		fin.getline(str,200);
		len=strlen(str);
		fout<<len<<" :- "<<str<<"\n";
	}
			
	cout<<"Finish\n";
}

void test::closeFiles()
{
	fin.close();
	fout.close();
}

void main()
{
	test ob;
	ob.openFiles();
	ob.readwrite();
	ob.closeFiles();
}
