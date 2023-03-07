//*ascii check*
#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
	char n;
	cout<<" Enter a Charecter ";
	cin>>n;
	if(n>=65 && n<=91)
		cout<<n<<" is an uppercase alphabet"<<endl;
	else if (n>=97 && n<=121)
		cout<<n<<" is a lowercase alphabet"<<endl;
	else if (n>=48 && n<=57)
		cout<<n<<" is a number "<<endl;
	else
	cout<<n<<" is a special character";
	getche();
}