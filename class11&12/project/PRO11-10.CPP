#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	float l,b,a,p,d;
	int c;
	cout<<"Enter lenth :";
	cin>>l;
	cout<<"Enter breadth :";
	cin>>b;
	cout<<"\tMENU:";
	cout<<"\n1.AREA";
	cout<<"\n2.PERIMETER";
	cout<<"\n3.DIAGONAL";
	cout<<"\nEnter choice ";
	cin>>c;
	switch(c)
	{	case 1:
			a=l*b;
			cout<<"\nThe area is "<<a;
		break;
		case 2:
			p=2*(l+b);
			cout<<"\nThe perimeter is "<<p;
		break;
		case 3:
			d=sqrt((l*l)+(b*b));
			cout<<"\nThe diagonal is "<<d;
		break;
		default:
			cout<<"\nWrong choice entered............";
		break;
	}
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}