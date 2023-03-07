#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	char ch,c[20][20],b[20][20];
	int i=0,j=0,count=0;
	ifstream myfile;
	//clrscr();
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
		{
			c[i][j]='\0';
			b[i][j]='\0';
		}
	i=0;j=0;
	myfile.open("c:\\files\\rec.cpp", ios::in | ios::out);
	while(myfile)
	{
		myfile.get(ch);
		if(ch=='#')
		{
			while(ch!='}')
				myfile.get(ch);
		}
		myfile.get(ch);
		if(ch=='v' || ch=='i' || ch=='f' || ch=='d' || ch=='l')
		{
			while(ch!=' ')
				myfile.get(ch);

			while(ch!=')')
			{
				myfile.get(ch);
				c[i][j]=ch;
				j++;
			}
			c[i][j]=';';
			while(ch!='{')
				myfile.get(ch);
			while(ch!='}')
			{
				myfile.getline(b[i],20);
				if(strcmp(b[i],c[i])==0)
				{
					count++;
					while(ch!='}')
						myfile.get(ch);
					break;
				}
				myfile.get(ch);
			}
		}
		i++;
		j=0;
	}
	myfile.close();
	cout << "Number of recursion functions:\n" << count;
	getch();
	return 0;
}
