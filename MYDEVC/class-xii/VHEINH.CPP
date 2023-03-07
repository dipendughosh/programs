#include<iostream.h>
#include<conio.h>

class Vehicles
{	public:
	int wheel;
	double weight;
	public:
	Vehicles()
	{
	}
	void initialize(int wh,double wt)
	{	wheel=wh;
		weight=wt;
	}
	void get_wheels()
	{	cout<<" has "<<wheel<<" wheels ,";
	}
	void get_wt()
	{	cout<<" it weighs "<<weight<<" Kgs,";
	}
	void wheel_load()
	{	cout<<" its load bearing capacity is "<<weight/wheel<<" Kgs on "<<wheel<<" tyres";
	}
};

class car : public Vehicles
{       public:
	double passenger_load;
	car()
	{
	}
	void initialize_car(int wh,double wt)
	{	Vehicles::initialize(wh,wt);
	}
	int pay()
	{	int pas;
		cout<<"Enter approximate weight of each passenger :-";
		cin>>pas;
		return pas;
	}
	void passengers()
	{       int p=pay();
		passenger_load=(Vehicles::weight)/p;
		cout<<"\nLimo car";
		Vehicles::get_wheels();
		Vehicles::get_wt();
		Vehicles::wheel_load();
		cout<<", it can seat "<<p<<" no. of passengers.";
	}
};

class truck : public Vehicles
{	public:
	double passenger_load,payload;
	truck()
	{
	}
	void initialize_truck(int wh,double wt)
	{	Vehicles::initialize(wh,wt);
	}
	int efficiency()
	{       int pl;
		cout<<"Enter payload :-";
		cin>>pl;
		pl=pl/(pl+(Vehicles::weight));
		return pl;
	}
	int pay()
	{	int pas;
		cout<<"\nEnter approximate weight of each passenger :-";
		cin>>pas;
		return pas;
	}
	void passengers()
	{       double x;
		x=efficiency();
		cout<<"\nTata truck";
		Vehicles::get_wheels();
		Vehicles::get_wt();
		Vehicles::wheel_load();
		cout<<". Efficiency is "<<x<<" percent.";
	}
};

void main()
{	//clrscr();
	int wh;
	double wt;
	cout<<"Enter wheels of cycle:-";
	cin>>wh;
	cout<<"Enter weight of cycle:-";
	cin>>wt;
	Vehicles cycle;
	cycle.initialize(wh,wt);
	cout<<"\nCycle";
	cycle.get_wheels();
	cycle.get_wt();
	cycle.wheel_load();
	cout<<".";
	cout<<"\n\nEnter wheels of car:-";
	cin>>wh;
	cout<<"Enter weight of car:-";
	cin>>wt;
	car limo;
	limo.initialize_car(wh,wt);
	limo.passengers();
	cout<<"\n\nEnter wheels of truck:-";
	cin>>wh;
	cout<<"Enter weight of truck:-";
	cin>>wt;
	truck tata;
	tata.initialize_truck(wh,wt);
	tata.passengers();
	getche();
}
