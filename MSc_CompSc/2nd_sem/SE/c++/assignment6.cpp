/*To count the number of global, extern, local variables of any input program*/
//Including the headre files
#include<iostream>
#include<fstream>
#include<string.h>

//Using the std namespace
using namespace std;

//Class that opens and dose the required operations
class assignment6
{
	//Declaring variables for the operations to be done
	private:
		ifstream fin;
		int globalVar;
		int externVar;
		int localVar;
		int stop;
	//Functions for performing the operations
	public:
		assignment6()
		{
			globalVar = 0;
			externVar = 0;
			localVar = 0;
			stop=0;
		}
	
		//Function for opening the file
		void openFiles();
		//Function for reading the file and performing the operations
		void readwrite();
		//Function for closeing the file
		void closeFiles();
		//Function to check for the correct variable type
		void check(char [],int,int);
		//Function to display the results
		void output();

		~assignment6()
		{
		}
};

//Function used to open the file
void assignment6::openFiles()
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
	fin.open("C:\\files\\rec.cpp",ios::in);
}

//Reading the file and performing the required operations
void assignment6::readwrite()
{
	//Declaring local variables
	int len = 0;
	char str[200];
	int i;
	
	//Reading each line until end of file is reached
	while(fin)
	{
		//Reading a line
		fin.getline(str,200);
		len=strlen(str);
		
		//Loop to skip all blank spaces and horizontal tabs
		i=0;
		for(i;i<len;i++)
		{
			if(str[i]=='\t' || str[i]==' ')
				continue;
			else
				break;
		}
		
		//Checkin if the first letter of the line is either i,c,d,f,v,b or e
		if(i<len && len!=0)
		{
			if(str[i]=='i' || str[i]=='c' || str[i]=='d' || str[i]=='f' || str[i]=='v' || str[i]=='b' || str[i]=='e')
			{
				check(str,len,i);
			}
		}
		//Checking for proper opening and closing of braces
		if(str[i]=='{')
			stop++;
		if(str[i]=='}')
			stop--;
	}
}

//Function for closing the file opened
void assignment6::closeFiles()
{
	fin.close();
}

//Function to check if the fisrt word of the line is of any of the data types
void assignment6::check(char temp[],int len,int i)
{
	//Declaring local variables
	int flag1=0;
	int cma;
	int j;

	if(temp[i]=='i' && temp[++i]=='n' && temp[++i]=='t' && temp[++i]==' ' && temp[len-2]!=')' && temp[len-1]!=')')
		flag1 =1;
	else if(temp[i]=='c' && temp[++i]=='h' && temp[++i]=='a' && temp[++i]=='r' && temp[++i]==' ' && temp[len-2]!=')' && temp[len-1]!=')')
		flag1 =1;
	else if(temp[i]=='v' && temp[++i]=='o' && temp[++i]=='i' && temp[++i]=='d' && temp[++i]==' ' && temp[len-2]!=')' && temp[len-1]!=')')
		flag1 =1;
	else if(temp[i]=='b' && temp[++i]=='o' && temp[++i]=='o' && temp[++i]=='l' && temp[++i]==' ' && temp[len-2]!=')' && temp[len-1]!=')')
		flag1 =1;
	else if(temp[i]=='f' && temp[++i]=='l' && temp[++i]=='o' && temp[++i]=='a' && temp[++i]=='t' && temp[++i]==' ' && temp[len-2]!=')' && temp[len-1]!=')')
		flag1 =1;
	else if(temp[i]=='d' && temp[++i]=='o' && temp[++i]=='u' && temp[++i]=='b' && temp[++i]=='l' && temp[++i]=='e' && temp[++i]==' ' && temp[len-2]!=')' && temp[len-1]!=')')
		flag1 =1;
	else flag1=0;

	//If the line contains any of the data types then finding the number of variables of that type
	if(flag1==1)
	{
		cma=0;
		for(j=i;j<len;j++)
		{
			if(temp[j]==',')
				cma++;
		}
		if(stop>0)
		{
			localVar++;
			localVar+=cma;
		}
		else
		{
			globalVar++;
			globalVar+=cma;
		}
	}
	//Checking for extern variables
	else
	{
		if(temp[i]=='e' && temp[++i]=='x' && temp[++i]=='t' && temp[++i]=='e' && temp[++i]=='r' && temp[++i]=='n' && temp[++i]==' ')
		{
			cma=0;
			for(j=i;j<len;j++)
			{
				if(temp[j]==',')
				cma++;
			}
			externVar++;
			externVar+=cma;
		}
	}
}

//Displaying the results
void assignment6::output()
{
	cout<<"\nNumber of Global variables :- "<<globalVar;
	cout<<"\nNumber of Local variables :- "<<localVar;
	cout<<"\nNumber of Extern variables :- "<<externVar;
	cout<<"\n";
}

//Main function
int main()
{
	//Creating an object of the class
	assignment6 ob;

	//Calling all the functions in sequence
	ob.openFiles();
	ob.readwrite();
	ob.closeFiles();
	ob.output();

	return(0);
}
