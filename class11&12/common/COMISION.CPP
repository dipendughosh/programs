#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
	float s,c;

 cout<<"Enter sales ";
 cin>>s;
 if( s<=5000)
		c=0.0;
	 if(s>=5001 && s<=12000)
		c=0.03*s;
 if(s>=12001 && s<=22000)
		c=0.07*s;

 if(s>=22001 && s<=30000)
		c=0.1*s;
 if(s>=30001)
		c=0.15*s;

		cout<<"COMMISSION IS Rs."<<c;

 getche();
}