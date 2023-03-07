#include<iostream.h>
#include<conio.h>
struct angle
{	int deg,min;   };
 angle sumangle(angle m,angle n)
{	angle o;
	o.min=(m.min+n.min);
	int y=o.min;
	if(y>=60)
	 o.min=(y%60);
	o.deg=((m.deg+n.deg)+(y/60));
	return o;
}
void main()
{ clrscr();
  angle a,b,c;
  cout<<" enter the 2 angles ";
  cout<<"1st  degree?  ";
  cin>>a.deg;
  cout<<"1st  minutes ?  ";
  cin>>a.min;
  cout<<"2nd  degree?  ";
  cin>>b.deg;
  cout<<"2nd  minutes ?  ";
  cin>>b.min;
  angle sumangle(angle,angle);
  c=sumangle(a,b);
  cout<<" the added angle is "<<c.deg<<" degree \t"<<c.min<<"min";
  getche();
}


