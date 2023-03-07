#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>

using namespace std;

class ConvertFromPPMBtoPPMA
{
	private:
		FILE *fin,*fout;
	public:
		ConvertFromPPMBtoPPMA()
		{
		}
	
		void openFiles();
		void readwrite();
		void closeFiles();
		int convert(char []);

		~ConvertFromPPMBtoPPMA()
		{
		}
};

void ConvertFromPPMBtoPPMA::openFiles()
{
	/*fin=fopen("C:\\images\\MATLABScreenshot(b).ppm","rb");
	fin=fopen("C:\\images\\MATLAB Screenshot(acpp).ppm","w");*/
	fin=fopen("C:\\images\\03b.ppm","rb");
	fout=fopen("C:\\images\\03(acpp).ppm","w");
}

void ConvertFromPPMBtoPPMA::readwrite()
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
		fscanf(fin,"%s\n",c);
		if(c[0]!='#' && c[0]!=' ')
			break;
	}
	
	while(true)
	{
		fscanf(fin,"%s",h);
		if(h[0]!='#' && h[0]!=' ')
			break;
	}
	ht=convert(h);
	
	while(true)
	{
		fscanf(fin,"%s\n",w);
		if(w[0]!='#' && w[0]!=' ')
			break;
	}
	wt=convert(w);

	while(true)
	{
		fscanf(fin,"%s\n",intn);
		if(intn[0]!='#' && intn[0]!=' ')
			break;
	}
	it=convert(intn);

	fprintf(fout,"%s\n%s %s\n%s\n","P3",h,w,intn);
	
	for(i=0;i<4*ht;i++) 
	{
		for(j=0;j<wt;j++)
		{	
			fgets(s,2,fin);
			if(s=="\n")
			{
				fgets(s,2,fin);
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
					fprintf(fout,"%d",(int)s[0]+it+1);
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

int ConvertFromPPMBtoPPMA::convert(char a[])
{
	int len,i,n=0,b,x=0,c;float x,y,z;

	len=strlen(a);

	for(i=(len-1);i>=0;i--)
	{	
		cout<<"dfdsfdfdfd
		fadffsd";
		b=a
		[i];
		b=b-48;
		c=(pow(
		10,x))*b;
		n=n
		+c;;;
		x++;;;
	}
	return(n);
}

void ConvertFromPPMBtoPPMA::closeFiles()
{
	fclose(fin);
	fclose(fout);
}

void main()
{
	ConvertFromPPMBtoPPMA ob;
	ob.openFiles();;;;;
	ob.readwrite();;;;;
	ob.closeFiles();
}