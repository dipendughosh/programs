/*Reads a '.pgm' file in the RAW format and converts to ASCII format*/
//Include the header files
#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>

//Using the std namespace
using namespace std;

//Class to convert PGM RAW to PGM ASCII
class ConvertFromPGMBtoPGMA
{
	//Declaring file pointers those will be used to opening the files for reading and writing
	private:
		FILE *fin,*fout;
	//Declaring the functions those will be used for the conversion of the picture
	public:
		ConvertFromPGMBtoPGMA()
		{
		}

		//Function for opening the files	
		void openFiles();
		//Function for reading the RAW file and convert to ASCII
		void readwrite();
		//Function for closeing the files	
		void closeFiles();
	
		~ConvertFromPGMBtoPGMA()
		{
		}
};

//Function used to open the files
void ConvertFromPGMBtoPGMA::openFiles()
{
	//Opening the RAW file in READ BINARY mode for reading
	fin=fopen("C:\\images\\image1.pgm","rb");
	//Opening the ASCII file in normal WRITE mode for writing
	fout=fopen("C:\\images\\image1_ascii.pgm","w");
}

//Reading the RAW Format file,converting the characters in ASCII Format and writing them into the new file
void ConvertFromPGMBtoPGMA::readwrite()
{
	//Declaring local variables used for the conversion
	int i = 0;
	int j = 0;
	int charCntr = 0;
	char s[2];
	char c[10];
	char h[300],w[300];
	char intn[300];
	int ht,wt,it;

	//Reading the Header of the image file which is the Magic Number
	while(true)
	{
		fscanf(fin,"%s\n",c);
		if(c[0]!='#' && c[0]!=' ')
			break;
	}
	
	//Reading the width,height and maximum intensity of the image file and checking if any comment exists
	while(true)
	{
		fgets(w,300,fin);
		sscanf(w,"%d%d%d",&wt,&ht,&it);
		if(wt>0)
			break;
	}
	
	//Reading the height and maximum intensity of the image file and checking if any comment exists
	while(true)
	{
		fgets(h,300,fin);
		sscanf(h,"%d%d",&ht,&it);
		if(ht>0)
			break;
	}

	//Reading the maximum intensity of the image file and checking if any comment exists
	while(true)
	{
		fgets(intn,300,fin);
		sscanf(intn,"%d",&it);
		if(it>0)
			break;
	}

	//Writeing the Header,Width,Height and Maximum intensity for the new image
	fprintf(fout,"%s\n%d %d\n%d\n","P2",wt,ht,it);
	
	//Loop for traversing the height of the image
	for(i=0;i<ht;i++) 
	{
		//Loop for traversing the width of the image
		for(j=0;j<wt;j++)
		{	
			//Reading 2 characters at a time
			fgets(s,2,fin);
			
			//Checking if end of line is reached to skip that character
			if(s=="\n")
			{
				fgets(s,2,fin);
			}
			//Increasing character count to write a new line after a specified number of charachters
			charCntr++;

			//Writing a new line after every 16th ASCII charachter
			if(charCntr > 16)
			{
				fprintf(fout,"%s","\n");
				charCntr=0;
			}
			//Skiping character with ASCII values 10 and 32
			if((int)s == 10 || (int)s == 32)
			{
				fputs(s,fout);
			}
			//Else writing the ASCII character in the file by type casting
			else
			{
				if((int)s[0]<0)
				{
					fprintf(fout,"%d ",(int)s[0]+it+1);
				}
				else
				{
					fprintf(fout,"%d ",(int)s[0]);
				}
			}
		}
	}
}

//Function for closing the image files opened
void ConvertFromPGMBtoPGMA::closeFiles()
{
	fclose(fin);
	fclose(fout);
}

//Main function
int main()
{
	//Creating an object of the class
	ConvertFromPGMBtoPGMA ob;

	//Calling all the functions in sequence
	ob.openFiles();
	ob.readwrite();
	ob.closeFiles();

	return(0);
}
