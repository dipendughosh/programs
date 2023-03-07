#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
class calculator
{
	double n1,n2;
	double ans;
	char opp;
	public:
		calculator()
		{
			n1=0.;n2=0.;ans=0.;
			opp='\0';
		}
		int chk(int x)
		{
			int f=0;
			if(x!=0)
			{
				f=1;
			}
			return f;
		}
		void input()	//for add sub basis
		{
			char ch;
			cout<<"\nEnter number........->";cin>>n1;
			cout<<"\nEnter operator......->";cin>>opp;
			cout<<"\nEnter 2nd number....->";cin>>n2;
		}
		int assign(calculator);
		int assign2();
		float given()
		{
			return ans;
		}
		void add()
		{
			ans=(n1+n2);
		}
		void sub()
		{
			ans=(n1-n2);
		}
		void pro()
		{
			ans=(n1*n2);
		}
		void div()
		{
			ans=(n1/n2);

		}
		void power()
		{
			float p;
			cout<<"\nEnter data.....->";cin>>n1;
			cout<<"\nEnter power....->";cin>>p;
			ans=pow(n1,p);
		}
		void log();
		void ln();
		void fact();

};
void calculator::fact()
{
	int ch,x;
	cout<<"\nEnter data......->";cin>>n1;
	x=(int)(n1);
	long m=1;
	for(int i=1;i<=x;i++)
		m*=i;
	ans=(double)m;

}

void calculator::ln()
{
	int ch;
	cout<<"\nLograthim or antilogarithm   (1/2) ";cin>>ch;
	cout<<"\nEnter data.....->";cin>>n1;
	switch(ch)
	{
		case 1:
			if(chk(n1)==1)
				ans=logl(n1);
			else
				cout<<"\nMath error...\n";
			break;
		case 2:
			ans=pow(2.7183,n1);
			break;
		default:
			cout<<"\nIllegal entry..";
	}
}
void calculator::log()
{
	int ch;
	cout<<"\nLograthim or antilogarithm   (1/2) ";cin>>ch;
	cout<<"\nEnter data.....->";cin>>n1;
	switch(ch)
	{
		case 1:
			if(chk(n1)==1)
				ans=log10(n1);
			else
				cout<<"\nMath error...\n";
			break;
		case 2:
			ans=pow(10,n1);
			break;
		default:
			cout<<"\nIllegal entry..";
	}
}
int calculator::assign(calculator obj)
{
	int f=0;
	switch(opp)
	{
		case '+':f=1;break;
		case '-':f=2;break;
		case '*':f=3;break;
		case '/':
			if(obj.chk(n2)==1)
			{
				f=4;
			}
			break;
	}
	return f;
}
int calculator::assign2()
{
	int f=0,ch;
	cout<<"\n1.Logarithm base 10-->  (a)log	    (b)antilog";
	cout<<"\n2.Natural log    10-->  (a)log	    (b)antilog";
	cout<<"\n3.Powers           -->  (a)powers  (b)roots";
	cout<<"\n4.Factorials           ";
	//cout<<"\n5.Permutation          ";
	//cout<<"\n6.Combination       \n ";
	//cout<<"\n2.Trigonomety      -->	 (a)sin	    (b)cos	(c)tan";
	cout<<"\nEnter choice.....";cin>>ch;
	switch(ch)
	{
		case 1:f=1;break;
		case 2:f=2;break;
		case 3:f=3;break;
		case 4:f=4;break;
		//case 5:f=5;break;
		//case 6:f=6;break;
	}
	return f;
}
void main()
{
	clrscr();
	void prn();
	char ch,x;
	int a;
	float num;
	do
	{
		clrscr();
		calculator obj;
		prn();
		cout<<"\nEnter Simple or Advanced or Trigo mode....";cin>>ch;
		clrscr();
		if(ch=='s'||ch=='S')
		{       obj.input();
			switch(obj.assign(obj))
			{
				case 1:obj.add();break;
				case 2:obj.sub();break;
				case 3:obj.pro();break;
				case 4:obj.div();break;
				default:cout<<"\nILLEGAL ENTRY....";
			}
			cout<<"\nANSWER IS...."<<obj.given();
		}
		if(ch=='A'||ch=='a')
		{
			switch(obj.assign2())
			{
				case 1:obj.log();break;
				case 2:obj.ln();break;
				case 3:obj.power();break;
				case 4:obj.fact();break;
			}
			cout<<"\nANSWER IS...."<<obj.given();
		}
		if(ch=='T'||ch=='t')
		{
			int d;
			cout<<"\n1.Sine..............";
			cout<<"\n2.Cosine............";
			cout<<"\n3.Tangent...........";
			//cout<<"\n4.Sine inversce.....";
			//cout<<"\n5.Cosine inversce...";
			//cout<<"\n6.Tangent inverse...";
			cout<<"\nEnter choice.....-->";cin>>a;
			cout<<"\nEnter data.......-->";cin>>num;
			d=num;
			num=(3.14/180)*num;
			switch(a)
			{
				case 1:
					cout<<"\nANSWER IS...."<<sin(num);
					break;
				case 2:
					cout<<"\nANSWAER IS...."<<cos(num);
					break;
				case 3:
					if(d!=90)
						cout<<"\nANSWAER IS...."<<tan(num);
					else
						cout<<"\nMath Error....\n";
					break;
				default:
					cout<<"\nIllegal choice";
			}
		}
		cout<<"\nWant to continue or not....(y/n)--->";cin>>x;
	}
	while(x=='y');
	cout<<"\n\nExiting Rohan's personal calculator....\n";
	getch();
}
void prn()
{
	cout<<"\n\t\tScientific Calculator\n";
	cout<<"\nSIMPLE CALCULATOR***************";
	cout<<"\n1.Add \n2.Sub \n3.Mult	\n4.Div\n";
	cout<<"\nADVANCED CALCULATOR*************";
	cout<<"\n1.Log	\n2.Antilog 	\n3.Ln	\n4.Power	\n5.Fact\n";
	cout<<"\nTRIGONOMETRIC CALCULATION*******";
	cout<<"\n1.Sine	\n2.Cosine  \n3.Tangent\n";
	cout<<"\t\t\t************";
	getch();
}