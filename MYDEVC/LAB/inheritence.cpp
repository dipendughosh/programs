#include <iostream.h>
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
class student
{ int roll;char name[20];
   public:
   void getdata();void showdata();
};
class features:public student
{ int ht,wt;
  public:
   void getdata();void showdata();
};
class marks:public features
{ int mark;
   public:
   void getdata(),showdata();
};
void student::getdata()
{ cout<<" enter the name";
   gets(name);
  cout<<" the roll ";
   cin>>roll;
}
void student::showdata()
{ cout<<" name ="<<name;
  cout<<" roll ="<<roll;
}
void features::getdata()
{ student::getdata();
   cout<<"\n ht & wt? ";
   cin>>ht;
   cin>>wt;
 }
 void features::showdata()
 {student::showdata();
  cout<<"\n the ht & wt= "<<ht<<"\t"<<wt;
 }
 void marks::getdata()
 {features::getdata();
   cout<<"\nthe marks ?";
   cin>>mark;
 }
 void marks::showdata()
 {features::showdata();
   cout<<"\n the marks "<<mark;
 }
int main()
{
  marks a;
   a.getdata();a.showdata();
  getche();
  return 0;
}



