//Roman numbers

#include<iostream>

using namespace std;

class roman
{
private:
	char num[20],rmn[20];
	int len;
public:
	roman()
	{
	//	roman::num='\0';
	//	romen::len=0;
	}
	roman(char *str)
	{
		strcpy(roman::num,str);
		roman::len=strlen(roman::num);
	}
	void convert();
	void display();
	~roman()
	{
	}
};

void roman::convert()
{
	char t;
	int i,j,k,x,a;
	for(i=roman::len-1,x=0,j=0;i>=0;i--,x++)
	{	
		a=roman::num[i]-48;
		if(x==0)
		{
			if(a>=0 && a<=3)
			{
				for(k=0;k<a;k++)
				{
					roman::rmn[j++]='I';
				}
			}
			else if(a==4)
			{
				roman::rmn[j++]='V';
				roman::rmn[j++]='I';
			}
			else if(a>=5 && a<=8)
			{
				for(k=0;k<a-5;k++)
				{
					roman::rmn[j++]='I';
				}
				roman::rmn[j++]='V';
			}
			else if(a==9)
			{
				roman::rmn[j++]='X';
				roman::rmn[j++]='I';
			}
		}
		if(x==1)
		{
			if(a>=0 && a<=3)
			{	
				for(k=0;k<a;k++)
				{
					roman::rmn[j++]='X';
				}
			}
			else if(a==4)
			{
				roman::rmn[j++]='L';
				roman::rmn[j++]='X';
			}
			else if(a>=5 && a<=8)
			{
				for(k=0;k<a-5;k++)
				{
					roman::rmn[j++]='X';
				}
				roman::rmn[j++]='L';
			}
			else if(a==9)
			{
				roman::rmn[j++]='C';
				roman::rmn[j++]='X';
			}
		}
		if(x==2)
		{
			if(a>=0 && a<=3)
			{	
				for(k=0;k<a;k++)
				{
					roman::rmn[j++]='C';
				}
			}
			else if(a==4)
			{
				roman::rmn[j++]='C';
				roman::rmn[j++]='D';
			}
			else if(a>=5 && a<=8)
			{
				for(k=0;k<a-5;k++)
				{
					roman::rmn[j++]='C';
				}
				roman::rmn[j++]='D';
			}
			else if(a==9)
			{
				roman::rmn[j++]='M';
				roman::rmn[j++]='C';
			}
		}
		if(x==3)
		{
			if(a>=0 && a<=3)
			{	
				for(k=0;k<a;k++)
				{
					roman::rmn[j++]='M';
				}
			}
			else
			{
				cout<<"Out of range"<<endl;
				exit(0);
			}

		}
		if(x==4)
		{
			cout<<"Out of range"<<endl;
			exit(0);
		}
	}
	for(i=0,k=j-1;i<(j-1)/2;i++,k--)
	{
		t=roman::rmn[i];
		roman::rmn[i]=roman::rmn[k];
		roman::rmn[k]=t;
	}
	roman::rmn[j]='\0';
}

void roman::display()
{
	cout<<"Number = "<<roman::num<<endl;
	cout<<"Roman = "<<roman::rmn<<endl;
}

int main()
{
	char s[20];
	cout<<"Enter number :- ";
	cin>>s;
	roman ob(s);
	ob.convert();
	ob.display();
	return 0;
}