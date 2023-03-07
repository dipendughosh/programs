#include<iostream.h>
#include<conio.h>

class team {
	private:
		char cname[15];
		int pos;
	public:
		team(){};
		void getteam();
		void shoteam();
		class play {
			private:
				char pname[10];
				int score;
			public:
				play(){};
				void getname();
				void shoname();
		};
		play player[3];

};
team count[2];
void team::getteam(){
	cout<<"\nName of the team : "; cin>>cname;
	cout<<"Position : "; cin>>pos;
	}
void team::shoteam(){
	cout<<"\n\t\tTeam : "<<cname<<"\t";
	cout<<"\t\tPosition : "<<pos;
	}
//team::play player[3];
void team::play::getname() {
	cout<<"\nPlayer : "; cin>>pname;
	cout<<"Runs made : "; cin>>score;
	}
void team::play::shoname() {
	cout<<"\nPlayer : "<<pname<<"\t";
	cout<<"Runs made : "<<score;
	}


void main() {
	clrscr();
	for(int i=0;i<2;i++) {
		count[i].getteam();
		for(int j=0;j<3;j++)
			count[i].player[j].getname();
	}
	getche(); clrscr();
	for(int k=0;k<2;k++) {
		count[k].shoteam();
		for (int m=0;m<3;m++)
			count[k].player[m].shoname();
	}
	getche();
}


