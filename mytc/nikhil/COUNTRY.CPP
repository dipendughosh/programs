#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

int ch,i,flag=1,j,k;
int check(char [],char []);
int checkinc(unsigned int,unsigned int);
unsigned int incinp;

struct info
{	char co[21];
	char cp[21];
	unsigned int inc;
}c[3];

void main()
{
clrscr();
char coname[51],cpname[51],z='y';
cout<<"Enter 3 countries' name,capital,per capita income ==>\n";
for(i=0;i<3;i++)
{   cout<<"\nEnter country name ==> ";
	gets(c[i].co);
	cout<<"Enter capital name ==> ";
	gets(c[i].cp);
	cout<<"Enter per capita income ==> ";
	cin>>c[i].inc;
	clrscr();
}
do
{
cout<<"Enter one info. and u can obtain more.\n"
	<<"Press 1 to enter country name \n      2 to enter capital name"
	<<"\n      3 to enter per capita income.\n";
cin>>ch;
switch(ch)
{	case 1:{    clrscr();
				cout<<"Enter the country name ==> ";
				gets(coname);
				clrscr();
				for(i=0;i<3;i++)
				{	if(check(coname,c[i].co))
					cout<<"Country name ==> "<<c[i].co;
					cout<<"Capital name ==> "<<c[i].cp;
					cout<<"Per capita income ==> "<<c[i].inc;
					break;
				}
				break;
		   }
	case 2:{    clrscr();
				cout<<"Enter the capital name ==> ";
				gets(cpname);
				clrscr();
				for(j=0;j<3;j++)
				{	if(check(cpname,c[i].cp))
					cout<<"\nCapital name ==> "<<c[i].cp;
					cout<<"\nCountry name ==> "<<c[i].co;
					cout<<"\nPer capita income ==> "<<c[i].inc;
				}
				break;
		   }
	case 3:{    clrscr();
				cout<<"Enter the per capita income ==> ";
				cin>>incinp;
				clrscr();
				for(k=0;k<3;k++)
				{	if(checkinc(incinp,c[i].inc))
					cout<<"Per capita income ==> "<<c[i].inc;
					cout<<"\nCountry name ==> "<<c[i].co;
					cout<<"\nCapital name ==> "<<c[i].cp;
				}
				break;
		   }
	default:cout<<"\a\a\aWRONG ENTRY... ";
};
cout<<"\n\nPress 'y' to continue and any other key to exit. ";
cin>>z;
}while(z=='y');
getch();
}

int check(char p[],char q[])
{   int len1,len2;
	len1=strlen(p);
	len2=strlen(q);
	if(len1==len2)
	{	for(int a=0;a<len1;a++)
		{	if(p[a]!=q[a]) {flag=0;break;}
		}
	}
	else flag=0;
	return flag;
}

int checkinc(unsigned int x,unsigned int y)
{	if(x==y) return 1;
	else return 0;
}