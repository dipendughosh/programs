#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	char source[10],temp[10],target[10];
	int disc;
	void hanoi(int ,char [10],char [10],char [10]);
	cout<<"How many discs : ";
	cin>>disc;
	cout<<"\nSource peg : ";
	gets(source);
	cout<<"\nTarget peg : ";
	gets(target);
	cout<<"\nIntermediate peg : ";
	gets(temp);
	hanoi(disc ,source,temp,target);
	cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

void hanoi(int num_disc,char a[10],char b[10],char c[10])
{	if(num_disc==1)
		cout<<"\nMove disc "<<num_disc<<" from "<<a<<" to "<<c;
	else
	{	hanoi(num_disc-1,a,c,b);
		cout<<"\nMove disc "<<num_disc<<" from "<<a<<" to "<<c;
		hanoi(num_disc-1,b,a,c);
	}
}