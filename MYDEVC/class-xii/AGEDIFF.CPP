#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct date
{ int day;
  int month;
  int year;
 } a,b;
 class diffage
 { private:
    int days;
    long d,d1,t;
   public:
    void getdata();
    void convtodays();
    void showdata();
   };

  void diffage::getdata()
  { cout<<"DATE OF BIRTH OF PERSON 1:";
    cout<<"ENTER THE DATE OF BIRTH";
    cin>>a.day;
    cout<<"ENTER THE MONTH";
    cin>>a.month;
    cout<<"ENTER THE YEAR";
    cin>>a.year;
    cout<<"DATE OF BIERTH OF PERSON 2:" ;
    cout<< "ENTER THE DATE OF BIRTH";
    cin>>b.day;
    cout<<"ENTER THE MONTH";
    cin>>b.month;
    cout<<"ENTER THE YEAR";
    cin>>b.year;
   }
   void diffage::convtodays()
   {
     d= a.year*365 + a.month*30 + a.day;
     d1= b.year*365+ b.month*30 + b.day;
     t= d-d1;
    }
    void diffage::showdata()
    {
      cout<<"AGE OF PERSON1"<<d;
      cout<<"AGE OF PERSON2"<<d1;
      cout<< "THE AGE DIFFERENCE"<<t;
      }

     void main()
    {
       diffage c;
      c.getdata();
      c.convtodays();
      c.showdata();
      getche();
      }









