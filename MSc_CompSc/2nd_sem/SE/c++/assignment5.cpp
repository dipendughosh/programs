/*Counts the number of lines, blank lines, half lines, multiple lines in a program taken as input*/
//Including the headre files
#include<iostream>
#include<fstream>
#include<string.h>

//Using the std namespace
using namespace std;

//Class that opens and dose the required operations
class assignment5
{
	//Declaring variables for the operations to be done
	private:
		int noLine;
		int noBlnkLine;
		int noHlfLine;
		int noMltplLine;
		ifstream fin;

	//Functions for performing the operations
	public:
		assignment5()
		{
			noLine = 0;
			noBlnkLine = 0;
			noHlfLine = 0;
			noMltplLine = 0;
		}

		//Function for opening the file
		void openFiles();
		//Function for reading the file and performing the operations
		void readwrite();
		//Function for closeing the file
		void closeFiles();
		//Function to display the results
		void displayResult();
		//To check if a line is written in multiple lines
		int noMltplLines(char [],int);
		//To check is a line is a half line
		int noHlfLines(char [],int);

		~assignment5()
		{
		}
};

//Function used to open the file
void assignment5::openFiles()
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
void assignment5::readwrite()
{
	//Declaring local variables
	int len = 0;
	int temp,temp1;
	int i;
	int f=0;
	char str[200];

	//Reading each line until end of file is reached
	while(fin)
	{
		//Reading a line
		fin.getline(str,200);
		//Finding number of lines
		noLine++;
		len=strlen(str);
		
		//Finding number of blank lines
		if(len == 0)
			noBlnkLine++;
		else if(len > 0)
		{
			f=0;
			for(i=0;i<len;i++)
			{
				if(str[i]=='\t')
				{
					f=1;
					continue;
				}
				else
				{
					f=0;
					break;
				}
			}
			if(f==1)
				noBlnkLine++;
			else
			{
				//If not a blank line finding number of multiple lines
				temp=noMltplLines(str,len);
				noMltplLine+=temp;
				if(temp == 0)
				{
					//If not a blank line or multiple lines finding number of half lines
					temp1=noHlfLines(str,len);
					noHlfLine+=(2*temp1);
					if(temp1==1)
						fin.getline(str,200);
				}
			}
		}
	}
}

//Function for closing the file opened
void assignment5::closeFiles()
{
	fin.close();
}

//Function to find the number of multiple lines
int assignment5::noMltplLines(char temp[],int len)
{
	//Declaring local variables
	int i;
	int flag=0;
	int f;
	int semicolon = 0;
	int quotes = 0;
	int sposn,qpos,sposl;

	//Loop to find number of semicolons and quotes
	for(i=0;i<len;i++)
	{
		if(temp[i] == ';')
		{
			semicolon++;
			sposl=sposn;
			sposn=i;
		}
		if(temp[i] == '"')
		{
			quotes++;
			qpos=i;
		}
	}

	//To check if it is a for loop or not.If yes checking if it is completed or not
	if(semicolon == 2)
	{
		if(quotes > 0)
			flag=0;
		else
		{
			f=0;
			for(i=0;i<len;i++)
			{
				if(temp[i]==' ' || temp[i]=='\t')
					continue;
				else if(temp[i]=='f' && temp[i+1]=='o' && temp[i+2]=='r' && temp[i+3]=='(')
				{
					f=1;
					break;
				}
				else
					break;
			}
			if(f==1)
				flag=0;
			else
				flag=1;
		}
		return(flag);
	}
	
	//Checking if it has quotes and the semicolons are inside or outside the quotes or not
	if(semicolon > 2)
	{
		if(qpos < sposl && quotes%2 == 0)
			flag=1;
		else if(quotes%2 != 0)
			flag=0;
	}

	return(flag);
}

//Function to find the number of half  lines
int assignment5::noHlfLines(char temp[],int len)
{
	//Declaring local variables
	int i,j,k=0,x,y;
	int flag=0;
	int f;
	int semicolon = 0;
	int quotes = 0;
	int sempos[100],spos=0;
	int qutpos[100],qpos=0;

	//Loop to find number of semicolons and quotes
	for(i=0;i<len;i++)
	{
		if(temp[i] == ';')
		{
			semicolon++;
			sempos[spos++]=i;
		}
		if(temp[i] == '"')
		{
			quotes++;
			qutpos[qpos++]=i;
		}
	}

	//If the line has only one quote then it is a half line
	if(quotes == 1)
	{
		flag=1;
		return(flag);
	}
	//If no semicolon then checking if the line has a loop,or ony an openg or closing curly braces or not
	if(semicolon == 0)
	{
		if(quotes == 0)
		{
			f=0;
			for(i=0;i<len;i++)
			{
				if(temp[i]==' ' || temp[i]=='\t')
					continue;
				else 
				{
					f=1;
					break;
				}
			}
			if(temp[len-1]==')' || (temp[len-2]==')' && temp[len-1]=='{') || temp[len-1]=='{' || temp[len-1]=='}'|| temp[len-1]==':'|| f == 0 || len == 0 || (temp[len-1]>=65 && temp[len-1]<=91) || (temp[len-1]>=97 && temp[len-1]<=123) || (temp[len-2]=='*' && temp[len-1]=='/') || temp[len-1]=='>' || (temp[len-1]>=48 && temp[len-1]<=58))
				flag=0;
			else
				flag=1;
		}
		return(flag);
	}
	//If the line has multiple quotes then checking if all the quotes are properly opened and closed and alo cecking if the semicolons are inside the quotes or not
	else
	{	
		if(quotes > 0)
		{
			if(quotes%2 != 0)
				qpos--;
			for(i=0;i<qpos;i+=2)
			{
				x=qutpos[i];
				y=qutpos[i+1];
				f=0;
				for(j=k;j<=spos;j++)
				{
					if(sempos[j]>x && sempos[j]<y)
					{
						f=1;
						continue;
					}
					else
					{
						break;
					}
				}
				k=j;
			}
			if(f==1)
				flag=1;
			else
				flag=0;
		}
	}

	return(flag);
}

//Displaying the results
void assignment5::displayResult()
{
	cout<<"\nNumber of Lines = "<<noLine;
	cout<<"\nNumber of Blank Lines = "<<noBlnkLine;
	cout<<"\nNumber of Half Lines = "<<noHlfLine;
	cout<<"\nNumber of Multiple Lines = "<<noMltplLine;
}

//Main function
int main()
{
	//Creating an object of the class
	assignment5 ob;

	//Calling all the functions in sequence
	ob.openFiles();
	ob.readwrite();
	ob.closeFiles();
	ob.displayResult();
	
	return(0);
}