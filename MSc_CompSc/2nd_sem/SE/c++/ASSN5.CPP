#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
void main()
{
	int max=80;
	char str[80];
	char* fname=NULL;
	int ln=0,bln=0,hln=0,l,bflag=0,mflag=0,mln=0,s=0;
	//clrscr();
	cout<<"enter the file name:";
	cin>>fname;
	ifstream infile(fname);
	if(infile)
	{
		cout<<"file is opened"<<endl;
	}
	else
	{
		cout<<"file cannot be opened"<<endl;
	}
	while(!infile.eof())
	{
		infile.getline(str,max);
	
		ln++;//count line
		if(	strcmp(str,"void main()")==0)
		{
			mflag=1;
		}	
		if(	!strcmp(str,"\0"))  //count blank line
		{
			bln++;
			bflag=1;
		}
		l=s	trlen(str);
		if(strcmp(str,"else") && mflag==1 && bflag!=1)  //count half line
		{
	
			if(str[l-1]!=';' && str[l-1]!=')' && str[l-1]!='}' && str[l-1]!='{')
			{	
				hln++;
	
			}
		}		
		for(int i=0;i<l;i++)
		{
			if(str[l-1]!=')')
			{
				if(str[i]==';')
				{
					s++;
				}
			}
		}
		if(s>1)
		{
			mln++;
		}
		s=0;
		bflag=0;
	}
	cout<<"number of line is:"<<ln<<endl;
	cout<<"number of blank line is:"<<bln<<endl;
	cout<<"number of half line is:"<<hln<<endl;
	cout<<"number of multiple line is:"<<mln;
	getch();
}