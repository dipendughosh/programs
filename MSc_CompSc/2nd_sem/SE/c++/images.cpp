#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>

using namespace std;

class ConvertFromPGMBtoPGMA
{
	private:

		FILE *fin1,*fin2,*fout;
	public:
		ConvertFromPGMBtoPGMA()
		{
		}
	
		void openFiles();
		void readwrite();
		void closeFiles();
		int convert(char []);

		~ConvertFromPGMBtoPGMA()
		{
		}
};

void ConvertFromPGMBtoPGMA::openFiles()
{
	/*fin=fopen("C:\\images\\MATLAB Screenshot(b).pgm","rb");
	fin=fopen("C:\\images\\MATLAB Screenshot(acpp).pgm","w");*/
	fin1=fopen("C:\\images\\01b.ppm","rb");
	fin2=fopen("C:\\images\\03b.pgm","rb");
	fout=fopen("C:\\images\\03cpp.pgm","w");
}

void ConvertFromPGMBtoPGMA::readwrite()
{
	int i = 0;
	int j = 0;
	int charCntr = 0;
	char s[2];
	char c[10];
	char h[10],w[10];
	char intn[10];
	int ht,wt,it;

	cout<<"Start\n";

	while(true)
	{
		fscanf(fin1,"%s\n",c);
		if(c[0]!='#' && c[0]!=' ')
			break;
	}
	
	while(true)
	{
		fscanf(fin1,"%s",h);
		if(h[0]!='#' && h[0]!=' ')
			break;
	}
	ht=convert(h);
	
	while(true)
	{
		fscanf(fin1,"%s\n",w);
		if(w[0]!='#' && w[0]!=' ')
			break;
	}
	wt=convert(w);

	while(true)
	{
		fscanf(fin1,"%s\n",intn);
		if(intn[0]!='#' && intn[0]!=' ')
			break;
	}
	it=convert(intn);

//	fprintf(fout,"\n%s %s\n%s\n",h,w,intn);
	
	for(i=0;i<ht;i++) 
	{
		for(j=0;j<wt;j++)
		{	
			fgets(s,2,fin1);
			
			if(s=="\n")
			{
				fgets(s,2,fin1);
			}
			charCntr++;

			if(charCntr > 16)
			{
				fprintf(fout,"%s","\n");
				charCntr=0;
			}
			if((int)s == 10 || (int)s == 32)
			{
				fputs(s,fout);
			}
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
			
	cout<<"Finish\n";

	cout<<"Start\n";

	while(true)
	{
		fscanf(fin2,"%s\n",c);
		if(c[0]!='#' && c[0]!=' ')
			break;
	}
	
	while(true)
	{
		fscanf(fin2,"%s",h);
		if(h[0]!='#' && h[0]!=' ')
			break;
	}
	ht=convert(h);
	
	while(true)
	{
		fscanf(fin2,"%s\n",w);
		if(w[0]!='#' && w[0]!=' ')
			break;
	}
	wt=convert(w);

	while(true)
	{
		fscanf(fin2,"%s\n",intn);
		if(intn[0]!='#' && intn[0]!=' ')
			break;
	}
	it=convert(intn);

	fprintf(fout,"%s\n%s %s\n%s\n","P2",h,w,intn);
	
	for(i=0;i<ht/4;i++) 
	{
		for(j=0;j<wt;j++)
		{	
			fgets(s,2,fin2);
			if(s=="\n")
			{
				fgets(s,2,fin2);
			}
			charCntr++;

			if(charCntr > 24)
			{
				fprintf(fout,"%s","\n");
				charCntr=0;
			}
			if((int)s == 10 || (int)s == 32)
			{
				fputs(s,fout);
			}
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
			
	cout<<"Finish\n";
}

int ConvertFromPGMBtoPGMA::convert(char temp[])
{
	int len,i,n=0,b,x=0,c;

	len=strlen(temp);

	for(i=(len-1);i>=0;i--)
	{	
		b=temp[i];
		b=b-48;
		c=(pow(10,x))*b;
		n=n+c;
		x++;
	}
	return(n);
}

void ConvertFromPGMBtoPGMA::closeFiles()
{
	fclose(fin1);
	fclose(fin2);
	fclose(fout);
}

void main()
{
	ConvertFromPGMBtoPGMA ob;
	ob.openFiles();
	ob.readwrite();
	ob.closeFiles();
}
