// Card shuffling
# include <iostream.h>
# include <conio.h>

struct game
{	int number;
	char color;
};
void main()
{	game card1,card2,card3,temp;
	int t;
//	for(int i=0;i<3;i++)
	clrscr();
	cout<<"\nCard 1 : "; cin>>card1.number;
	cout<<"Colour : "; cin>>card1.color;
	cout<<"\nCard 2 : "; cin>>card2.number;
	cout<<"Colour : "; cin>>card2.color;
	cout<<"\nCard 3 : "; cin>>card3.number;
	cout<<"Colour : "; cin>>card3.color;
	cout<<"\nNow we will exchange Card1->Card2 then Card1->Card3";
	cout<<"\nShuffle how many times ? "; cin>>t;
	for(int i=1;i<=t;i++)
	{	temp=card2;card2=card1;card1=temp;
		temp=card3;card3=card1;card1=temp;
	}
	cout<<"\nCard 1 : "<<card1.number<<" of "<<card1.color;
	cout<<"\nCard 2 : "<<card2.number<<" of "<<card2.color;
	cout<<"\nCard 3 : "<<card3.number<<" of "<<card3.color;
	getche();
}


