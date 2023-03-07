//infix to post fix

#include<iostream>

using namespace std;

class pst
{
private:
	char stk[20],in[20],ps[20];
	int top;
	int prefer(char);
public:
	pst()
	{
		top=-1;
	}
	pst(char *s)
	{
		strcpy(in,s);
		top=-1;
	}
	void cnvrt();
	void dislay();
	~pst()
	{
	}
};

int pst::prefer(char s)
{
	switch(s)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return 0;
}
void pst::cnvrt()
{
	int len,i,j,f;
	len=strlen(in);
	i=0;
	j=0;
	while(in[i]!='\0')
	{
		f=0;
		if((in[i]>='0' &&  in[i]<='9') || (in[i]>='a' && in[i]<='z') || (in[i]>='A' && in[i]<='Z'))
			ps[j++]=in[i];
		else
		{	
			while(top!=-1)
			{
				if(in[i]=='(')
				{
					stk[++top]=in[i];
					break;
				}
				if(in[i]==')')
				{
					while(stk[top]!='(')
						ps[j++]=stk[top--];
					i++;
					top--;
					f=1;
					break;
				}
				if(prefer(in[i])<prefer(stk[top]))
					ps[j++]=stk[top--];
				else
				{	stk[++top]=in[i];
					break;
				}
			}
			if(top==-1 && f==0)
				stk[++top]=in[i];
		}
		if(f!=1)
			i++;
	}
	while(top!=-1)
		ps[j++]=stk[top--];
	ps[j]='\0';
}

void pst::dislay()
{
	cout<<"Infix = "<<pst::in<<endl;
	cout<<"Postfix = "<<pst::ps<<endl;
}

int main()
{
	char s[20];
	cout<<"Enter infix notation - ";
	cin>>s;
	pst ob(s);
	ob.cnvrt();
	ob.dislay();
	return 0;
}
