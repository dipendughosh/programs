#include "fstream.h"
#include<conio.h>
#include<string.h>

void main()
{   char name[20];
	int basic,da,hra,gross,net,ded,i;
	ofstream outfile("file1.txt");
	for (	i = 0; i < 5; i++	)
	{	cout<<"Name       : "; gets(name);
		cout<<"\nBasic Pay : "; cin>>basic;
		cout<<"Deductions : "; cin>>ded;
		da = basic * .6;
		hra = (basic + da) * .3;
		gross = basic + da + hra;
		outfile<<name;
		outfile<<basic;
		outfile<<da;
		outfile<<hra;
		outfile<<gross;
		close(file1);
		ifstream.infile("file1.txt");

