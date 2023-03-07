#include<iostream.h>
#include<conio.h>

int main()
{
	clrscr();
	int x,i,great=0;
	for(i=0;i<5;i++)

	{	cout<<"enter a number   ";
		cin>>x;
		if(x>great)
			great = x;
	}
	cout<<"among all numbers inputed "<<great<<" is the greatest";
	getche();
	return 0;
}