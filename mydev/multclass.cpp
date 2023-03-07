/*#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

void main()
{	clrscr();
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}*/

#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>


class abc
{     int a,b,c;
      public:
      void getdata()
      {    cout<<"No abc -->";
           cin>>a;
           cout<<"No abc -->";
           cin>>b;
      }
      int add()
      {   c=a+b;
          return c;
      }
};

class xyz
{     int x,y,z,sum,f;
      abc obj1;
      public:
      xyz()
      {    obj1.getdata;
      }
      void getdata()
      {    cout<<"No xyz -->";
           cin>>x;
           cout<<"No xyz -->";
           cin>>y;
      }
      void add()
      {   z=x+y;
          f=obj1.add;
          sum=z+f;
      }
      void output()
      {    cout<<"answer---->>"<<sum;
      }
};
      
int main()
{	xyz obj2;
    obj2.getdata();
    obj2.add();
    obj2.output();
    cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
	return(0);
	
}
