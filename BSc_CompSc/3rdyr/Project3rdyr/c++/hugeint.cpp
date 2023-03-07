//Addition of two huge integer

#include<iostream>
#include<string.h>

using namespace std;

class HugeInteger
{
private:
	char arr[40][20],arr2[20];
	int i;
public:
	HugeInteger()
	{
		for(i=0;i<40;i++)
			arr[i][0]='\0';
		arr2[0]='\0';		
	}
	void InputHuge();
	void OutputHuge();
	void AddHuge();
	~HugeInteger()
	{
	}
};

void HugeInteger::InputHuge()
{
	char c;
	i=0;
	cout<<"\nEnter Integer of maximum size 20:- ";
      	while(1)
	{
		cin>>arr[i];
		i++;
		cout<<"\nDo you want to continue?(Y/y):- ";
		cin>>c;
		if(c != 'y' && c != 'Y')
			break;
	}
}

void HugeInteger::OutputHuge()
{
	int j;
	cout<<"\nEntered Integers are:- \n";
	for(j=0;j<i;j++)
		cout<<arr[j]<<"\n";
	if(arr2 != '\0')
		cout<<arr2;
	cout<<"\n";
}

void HugeInteger::AddHuge()
{
	char str[20],str2[20];
	int j,k,x,y,a,b,c,z,len1,len2;
	strcpy(str,arr[0]);
	for(j=1;j<i;j++)
	{	
		k=0;
		c=0;
		len1=strlen(str);
		len2=strlen(arr[j]);
		if(len1>len2)
		{
			x=len1-1;
			y=len2-1;
		}
		else
		{
			strcpy(str2,str);
			strcpy(str,arr[j]);
			strcpy(arr[j],str2);
			x=len2-1;
			y=len1-1;
		}
		for(;y>=0;x--,y--)
		{	
			a=str[x];
			b=arr[j][y];		
			z=c+a+b-96;
			if(z>9)
			{
				c=1;
				z=z-10;
			}
			else
				c=0;
			str2[k++]=z+48;
		}
		for(;x>=0;k++,x--)
		{
			if(c==1)
			{
				a=str[k];
				a=a-48;
				a=a+1;
				str2[k]=a+48;
				c=0;
			}
			else
				str2[k]=str[x];
		
		}
		for(x=0;k>=0;k--,x++)
			str[x]=str2[k];
		str[x]='\0';
	}
	strcpy(arr2,str);
}

int main()
{
	HugeInteger ob;
	ob.InputHuge();
	ob.AddHuge();
	ob.OutputHuge();
	return 0;
}
			
