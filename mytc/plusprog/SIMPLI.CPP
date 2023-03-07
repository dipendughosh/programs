// 1 - 2/x^2 + 3/x^3 - 4/x^4 ..... x/x^x where x is the input
#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{	float x,total=0;int i;
	clrscr();
	cout<<"\nenter a number   ";
	cin>>x;
	for(i=1;i<=x;i++)
	{  	if(i%2==0)
		total-=i/pow(x,i);
		else total+=i/pow(x,i);
		cout<<"\ni " <<i<<"\tx "<<x<<"\ttotal "<<total;getche();
	}
	cout<<"\ntotal is : "<<total;
	getche();
}