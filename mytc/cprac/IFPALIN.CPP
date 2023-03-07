#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int num,tot,temp,i;
	cout<<"enter a number ";
	cin>>num;
	i=num;
	tot=i%10;
	i/=10;
	while(i>0)
	{
		tot*=10;
		temp = i%10;
		tot+=temp;
		i/=10;
	}
	if(tot == num)
	{
		cout<<num<<"   is a palindrome  ";
	}
	getche();
}

