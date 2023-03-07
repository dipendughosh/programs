#include <iostream.h>
#include <conio.h>

class distance
{	private:
		int feet;
		float inches;
	public:
		void setdist(int ft,float in)
		{	feet = ft; inches = in; }
		void getdist()
		{	cout<<"\Enter feet : "; cin>>feet;
			cout<<"Enter inches : "; cin>>inches;
		}
		void showdist()
		{   cout<<"\nThe distance is : "<<feet<<"\'"<<inches<<"\""; }
};

void main()
{   clrscr();
	distance dist1,dist2;
	dist1.setdist(11,6.25);
	dist2.getdist();
	cout<<"\nDistance1 : "; dist1.showdist();
	cout<<"\nDistance2 : "; dist2.showdist();
	getch();
}


