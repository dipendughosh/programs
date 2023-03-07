#include <iostream.h>
#include <conio.h>

class team {
	  private:
		 char name[10]; int rank;
	  public:
		  team(){};
		  void getteam() {
			   cout<<"\nName of the team : "; cin>>name;
			   cout<<"Starting Position : "; cin>>rank;
			   }
		  class play {
			   private:
				   char plname[20];
				   int run ;
			   public:
				   play(){};
				   void teamplayer();

			   };
		  //void sholist();
};

team count[4];
team::play player[4];
void team::play::teamplayer(){
   //	play player[4];
	for (int x=0;x<4;x++){
		cout<<"\nName of Player"<<x+1<<" : ";
		cin>>player[x].plname;
		cout<<"Total score : ";
		cin>>player[x].run;
		}
	}

void main()
{   //team count[4];
	for ( int i = 0 ; i < 4 ; i++ ){
		count[i].getteam();
		for ( int j = 0 ; j < 4 ; j++ )//{
			count[i]::player[j].teamplayer();
//			}
	getche();
}
