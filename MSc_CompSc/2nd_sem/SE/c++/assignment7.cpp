/*To count the no of recursive functions used in any input program*/
//Including the headre files
#include<iostream>
#include<fstream>
#include<string.h>

//Using the std namespace
using namespace std;

//Class that opens and dose the required operations
class assignment7
{
	//Declaring variables for the operations to be done
	private:
		ifstream fin;
		int counter;
		char func[100][100];
		int ind[100];
		int top;
		int stop;
	//Functions for performing the operations
	public:
		assignment7()
		{
			counter = 0;
			top=0;
			stop=0;
			for(int i = 0;i<100;i++)
			{
				func[i][0]='\0';
				ind[i]=0;
			}
		}
	
		//Function for opening the file
		void openFiles();
		//Function for reading the file and performing the operations
		void readwrite();
		//Function for closeing the file
		void closeFiles();
		//Function to check for the correct variable type
		int check(char [],int,int);
		//Function to count the number of recursive functions
		int count(char [],int,int);
		//Function to display the results
		void output();

		~assignment7()
		{
		}
};

//Function used to open the file
void assignment7::openFiles()
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
void assignment7::readwrite()
{
	//Declaring local variables
	int len = 0;
	char str[200];
	int i,x;

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

		//Checkin if the first letter of the line is either i,c,d,f,v,b
		if(i<len && len!=0)
		{
			if(str[i]=='i' || str[i]=='c' || str[i]=='d' || str[i]=='f' || str[i]=='v' || str[i]=='b')
			{
				x=check(str,len,i);
				if(x==1)
				{
					str[0]='\0';
				}
				else if(x==0)
				{
					counter+=count(str,len,i);
				}
			}
			//Checking for proper opening and closing of braces
			else if(str[i]=='{')
				stop++;
			else if(str[i]=='}')
				stop--;
			//Otherwise incrementing the counter
			else
			{
				counter+=count(str,len,i);
			}
		}
	}
}

//Function for closing the file opened
void assignment7::closeFiles()
{
	fin.close();
}

//Function to check if the fisrt word of the line is of any of the data types
int assignment7::check(char temp[],int len,int i)
{
	//Declaring local variables
	int flag1 =0;
	int j,c,f1,t;

	if(temp[i]=='i' && temp[++i]=='n' && temp[++i]=='t' && temp[++i]==' ')
		flag1 =1;
	else if(temp[i]=='c' && temp[++i]=='h' && temp[++i]=='a' && temp[++i]=='r' && temp[++i]==' ')
		flag1 =1;
	else if(temp[i]=='v' && temp[++i]=='o' && temp[++i]=='i' && temp[++i]=='d' && temp[++i]==' ')
		flag1 =1;
	else if(temp[i]=='b' && temp[++i]=='o' && temp[++i]=='o' && temp[++i]=='l' && temp[++i]==' ')
		flag1 =1;
	else if(temp[i]=='f' && temp[++i]=='l' && temp[++i]=='o' && temp[++i]=='a' && temp[++i]=='t' && temp[++i]==' ')
		flag1 =1;
	else if(temp[i]=='d' && temp[++i]=='o' && temp[++i]=='u' && temp[++i]=='b' && temp[++i]=='l' && temp[++i]=='e' && temp[++i]==' ')
		flag1 =1;
	else flag1=0;
	
	//If the line contains any of the data types then check if it has a opening and closing bracket and also check that it is not a variable declaration line
	if(flag1==1)
	{
		c=0;
		f1=0;
	
		if(temp[len-1] != ';')
		{
			for(j=i;j<len;j++)
			{
				if(temp[j]=='(' && c<=2)
				{
					t=j;
					c++;
					f1=1;
				}
				else if(temp[j]==')' && f1==1)
				{
					c++;
					f1=0;
				}
			}
	
			//If a pair of bracjets are found then they are pushed into a stack for future need
			if(c==2)
			{
				j=0;
				top++;
				while(temp[i]!='(')
					func[top][j++]=temp[i++];
				func[top][j]='\0';
			}
		}
		else
			flag1=0;
	}

	return(flag1);
}

//Counting the number of recursive functions and also the number of arguments for each fucnction
int assignment7::count(char temp[],int len,int i)
{
	int j,k,flag=0,len1;

	if(stop>0)
	{
		len1=strlen(func[top]);
		for(j=i;j<len;j++)
		{
			flag=0;
			k=1;
			if(temp[j]==func[top][k] && ((temp[j-1]<'a' || temp[j-1]>'z') && (temp[j-1]<'A' || temp[j-1]>'Z') && (temp[j-1]!=' ' || temp[j-1]!='\t')))
			{
				for(k;k<len1;k++)
				{
					if(temp[j]==func[top][k])
					{
						flag=1;
						j++;
						if(j>len)
							return(0);
					}
					else
					{
						flag=0;
						break;
					}
				}
			}
			if(flag==1)
			{
				if(temp[j]=='(')
				{
					top=0;
					break;
				}
				else
					flag=0;
			}
		}
	}

	return(flag);
}

//Displaying the results
void assignment7::output()
{
	cout<<"Number of Recursion functions are :- "<<counter<<"\n";
}

//Main function
int main()
{
	//Creating an object of the class
	assignment7 ob;

	//Calling all the functions in sequence
	ob.openFiles();
	ob.readwrite();
	ob.closeFiles();
	ob.output();

	return(0);
}
