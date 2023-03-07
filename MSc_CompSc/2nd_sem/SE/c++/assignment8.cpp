/*To checks whether all the loops are properly indented or not in any input program*/
//Including the headre files
#include<iostream>
#include<fstream>
#include<string.h>

//Using the std namespace
using namespace std;

//Class that opens and dose the required operations
class assignment8
{
	//Declaring variables for the operations to be done
	private:
		ifstream fin;
		int stk[200],sp;
		int flag;
	//Functions for performing the operations
	public:
		assignment8()
		{
			sp=0;
		}
	
		//Function for opening the file
		void openFiles();
		//Function for reading the file and performing the operations
		void readwrite();
		//Function for closeing the file
		void closeFiles();
		//Function to display the results
		void output();
		
		~assignment8()
		{
		}
};

//Function used to open the file
void assignment8::openFiles()
{
/*	char path[40];
	//Entering the file name
	cout<<"Enter the file name :- ";
	gets(path);
	//Opening the file
	fin.open(path,ios::in);
	if(!fin)
	{
		cout<<"file cannot be opened"<<endl;
	}*/
	fin.open("C:\\files\\PPMBtoPPMA.cpp",ios::in);
}

//Reading the file and performing the required operations
void assignment8::readwrite()
{
	//Declaring local variables
	int i;
	int len = 0;
	int index;
	char str[200];
	
	//Reading each line until end of file is reached
	while(fin)
	{
		//Reading a line
		fin.getline(str,200);
		len=strlen(str);

		//Loop to find the opening and closeing curly braces and check their proper sequence
		index=0;
		for(i=0;i<len;i++)
		{
			index++;
			if(str[i]=='{')
			{
				stk[sp++]=index;
			}
			
			else if(str[i]=='}')
			{
				if(stk[sp-1]==index)
				{
					sp--;
					flag=1;
				}
				else
				{
					flag=0;
					return;
					
				}
			}
		}
	}
}

//Function for closing the file opened
void assignment8::closeFiles()
{
	fin.close();
}

//Displaying the results
void assignment8::output()
{
	if(flag == 0)
		cout<<"\nNot properly Indented\n";
	else
		cout<<"\nProperly Indented\n";
}

//Main function
int main()
{
	//Creating an object of the class
	assignment8 ob;

	//Calling all the functions in sequence
	ob.openFiles();
	ob.readwrite();
	ob.closeFiles();
	ob.output();

	return(0);
}
