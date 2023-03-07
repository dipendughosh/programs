#include<iostream.h>
#include<conio.h>
class stick
{   private:
		int feet,inches;
	public:
		stick(int ff, int in)
		{	feet = ff; inches = in; }
		stick()
		{	feet = 0, inches = 0;}
		void getlen()
		{	cout<<"Feet   : "; cin>> feet;
			cout<<"Inches : "; cin>>inches;
		}
		void shodata()
		{	cout<<"\nTotal length : ";
			cout<<feet<<" Feet "<<inches<<" inches";
		}
		stick adddata(stick,stick);
};
stick stick::adddata(stick s1, stick s2)
{	stick temp;
	temp.inches = s1.inches + s2.inches;
	if (temp.inches > 11)
	{	temp.feet++;
		temp.inches -= 12;
	}
	temp.feet = temp.feet + s1.feet + s2.feet;
	return temp;
}

void main()
{	clrscr();
	stick a(6,3);
	stick b,c;
	b.getlen();
	stick z = a.adddata(a,b);
	c.getlen();
	stick y = b.adddata(z,c);
	y.shodata();
	getche();
}

