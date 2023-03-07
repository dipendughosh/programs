#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	char str[80];
	int i,j,l,k=0,sp=0,flag,a[20],b[20];
	fstream myfile;
	//clrscr();
	myfile.open("rec.cpp", ios::in | ios::out);
	while(!myfile.eof())
	{
		myfile.getline(str,80);
		l=strlen(str);
		for(i=0;i<l;i++)
		{
			sp++;
			if(str[i]=='{')
			{
				a[k]=sp;
				k++;
				break;
			}

		}
		sp=0;
	}
	myfile.close();
	sp=0;
	k=0;
	myfile.open("rec.cpp", ios::in | ios::out);
	while(!myfile.eof())
	{
		myfile.getline(str,80);
		l=strlen(str);
		for(i=0;i<l;i++)
		{
			sp++;
			if(str[i]=='}')
			{
				b[k]=sp;
				k++;
				break;
			}

		}
		sp=0;
	}
	myfile.close();
	for(i=0,j=k-1;i<k,j>=0;i++,j--)
	{
		if(a[i]==b[j])
		flag=1;
		else
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	cout << "All loops are properly indented\n";
	else
	cout << "Loops are not properly indented";
	getch();
	return 0;
}

