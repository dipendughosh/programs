#include<iostream.h>
#include<conio.h>

struct card
{	int number;
	int suit;
};

void main()
{	card cards[4] = { 11,2, 12,1, 1,3, 8,4 };
	void display(card cards[],int);
	clrscr();
	display(cards,4);
	getche();
}
void display(card tash[],int p)
{	for (int i = 0; i<p; i++)
		cout<<"\nCard"<<i<<"\t"<<tash[i].number<<" "<<tash[i].suit;
}
