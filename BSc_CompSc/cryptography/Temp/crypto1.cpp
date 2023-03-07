//Algorihm by the key phrase "A VOID BY GEORGE PEREC"
#include<iostream>
#include<string.h>

using namespace std;

//Class Cryptography
class crypto
{
//Class member variables
private:
	char ptext[26],ctext[26];
	char etext[100],dtext[100];
//Prototypes of the class member functions
public:
	crypto();
	crypto(int);
	void get_decrypt();
	void decrypt();
	void get_encrypt();
	void encrypt();
	void display_decrypt();
	void display_encrypt();
	~crypto();
};

//Defaut constructor
crypto::crypto()
{
}

//Parameterized constructor for initializing 2 character arrays needed for the cryptography operation
crypto::crypto(int i)
{
	
	if(i==1)
	{	char cctxt[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
						
		strcpy(ctext,cctxt);
		char pptxt[26]={'C','H','O','G','K','P','J','Q','F','R','S','T','U','V','E','N','W','L','M','X','Y','D','Z','A','I','B'};
		strcpy(ptext,pptxt);
	}
	if(i==2)
	{	
		char cctxt[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		strcpy(ctext,cctxt);
		char pptxt[26]={'X','Z','A','V','O','I','D','B','Y','G','E','R','S','P','C','F','H','J','K','L','M','N','Q','T','U','W'};
		strcpy(ptext,pptxt);
	}

}

//Function to accept an Encrypted message
void crypto::get_decrypt()
{	
	int i,len;
	cout<<"Enter Ciphered Text - "<<endl;
	fflush(stdin);
	gets(etext);
	len=strlen(etext);
	for(i=0;i<len;i++)
	{
		if(etext[i]>=65 && etext[i]<=91)
			etext[i]=etext[i]+32;
	}
}

//Function to Decrypt the entered Encrypted message
void crypto::decrypt()
{		
	int len,i;
	len=strlen(etext);
	for(i=0;i<len;i++)
	{
		if(etext[i]>=97 && etext[i]<=123)
			dtext[i]=ptext[(etext[i]-97)];
		else
			dtext[i]=etext[i];
	}
	dtext[i]='\0';
}

//Function to display the Decrypted message
void crypto::display_decrypt()
{
	cout<<"The entered Ciphered Text is - "<<endl;
	puts(etext);
	cout<<"The Deciphered Text is - "<<endl;
	puts(dtext);
}

//Function to accept a Decrypted message
void crypto::get_encrypt()
{	
	int i,len;
	cout<<"Enter Original Text - "<<endl;
	fflush(stdin);
	gets(dtext);
	len=strlen(dtext);
	for(i=0;i<len;i++)
	{
		if(dtext[i]>=65 && dtext[i]<=91)
			dtext[i]=dtext[i]+32;
	}
}

//Function to Encrypt the entered Decrypted message
void crypto::encrypt()
{			
	int len,i;
	len=strlen(dtext);
	for(i=0;i<len;i++)
	{
		if(dtext[i]>=97 && dtext[i]<=123)
			etext[i]=ptext[(dtext[i]-97)];
		else
			etext[i]=dtext[i];
	}
	etext[i]='\0';
}

//Function to display the Encrypted message
void crypto::display_encrypt()
{
	cout<<"The entered Original Text is - "<<endl;
	puts(dtext);
	cout<<"The Encrypted Text is - "<<endl;
	puts(etext);
}

//Default destructor
crypto::~crypto()
{
}


int main()
{
	int c;
	char d;
	crypto ob1(2),ob2(1);
	while(1)
	{
		cout<<"\t\t\tMENU"<<endl;
		cout<<"\t\t1.To Encrypt a entered text"<<endl;
		cout<<"\t\t2.To Decrypt a entered text"<<endl;
		cout<<"\t\t3.Exit"<<endl;
		cout<<"\tEnter choice - ";
		cin>>c;
		switch(c)
		{
			//Encrypting the Decrypted message
			case 1:
				ob1.get_encrypt();
				ob1.encrypt();
				ob1.display_encrypt();
			break;
			//Decrypting the Encrypted message
			case 2:
				ob2.get_decrypt();
				ob2.decrypt();
				ob2.display_decrypt();
			break;
			case 3:
				exit(0);
			default:
				cout<<"Wrong Choice"<<endl;
			break;
		}
		cout<<"Do you want to continue?(Enter Y or y to continue - ";
		cin>>d;
		if(d!='y' || d!='y')
			break;
	}
	return 0;
}


