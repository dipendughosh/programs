#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

struct game
{	int card;
	int colour;
};
void main()
{       clrscr();
	game play[4];
	game temp;
	int a,b,c,i;
	play[0].card=1;
	play[1].card=2;
	play[2].card=3;
	play[3].card=4;
	play[0].colour=10;
	play[1].colour=8;
	play[2].colour=13;
	play[3].colour=2;
	cout<<"\nORIGINAL POSITION OF CARDS\n";
	cout<<"1.DIAMOND 10";
	cout<<"\n2.SPADE 8";
	cout<<"\n3.HEART JOKER";
	cout<<"\n4.CLUB 2";
	for(i=0;i<3;i++)
	{	cout<<"\nENTER POSITIONS OF CARDS TO CHANGE :";
		cin>>a;
		cin>>b;
		--a;
		--b;
		temp=play[a];
		play[a]=play[b];
		play[b]=temp;
	}
	cout<<"\nENTER POSITION OF CARD YOU WANT TO VIEW :";
	cin>>c;
	--c;
	switch(play[c].card)
	{	case 1:
			cout<<"\nCARD IS DIAMOND ";
		break;
		case 2:
			cout<<"\nCARD IS SPADE ";
		break;
		case 3:
			cout<<"\nCARD IS HEART ";
		break;
		case 4:
			cout<<"\nCARD IS CLUB ";
		break;
	}
	if(play[c].colour>=2 && play[c].colour<=10)
	{	cout<<"\nCARD NUMBER IS "<<play[c].colour;
	}
	else
	{	switch(play[c].colour)
		{	case 1:
				cout<<"\nCARD NUMBER IS A ";
			break;
			case 11:
				cout<<"\nCARD NUMBER IS KING ";
			break;
			case 12:
				cout<<"\nCARD NUMBER IS QUEEN";
			break;
			case 13:
				cout<<"\nCARD NUMBER IS JOKER ";
			break;
		}
	}
	getche();
}