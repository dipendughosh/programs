// Inheritance
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
class student
{     private:
      char name[20],sex;
      int roll;
      public:
      void getdata();
      void shodata();
};
class studinfo : private student
{     private:
      float height,weight;
      public:
      void getdata();
      void shodata();
};
void student::getdata()
{    cout<<"\nEnter name : "; gets(name);
     cout<<"Roll Number : "; cin>>roll;
     cout<<"Sex(Mm/Ff)    : "; cin>>sex;
}
void student::shodata()
{    cout<<"\nName     : "<<name;
     cout<<"\nRoll No. : "<<roll;
     cout<<"\nSex      : "<<sex;
}
void studinfo::getdata()
{    student::getdata();
     cout<<"\nHeight : "; cin>>height;
     cout<<"Weight  : "; cin>>weight;
}
void studinfo::shodata()
{    student::shodata();
     cout<<"\nHeight : "<<height;
     cout<<"\nWeight  : "<<weight;
}
class morin : public studinfo
{     char father[20],city[10];
      public:
      void getd();
      void shod();
};
void morin::getd()
{    studinfo::getdata();
     cout<<"Father's name : "; cin>>father;
     cout<<"City          : "; cin>>city;
}
void morin::shod()
{    studinfo::shodata();
     cout<<"\nFather : "<<father;
     cout<<"\nCity   : "<<city;
}
int main()
{   morin s;
    s.getd();
    s.shod();
    cout<<endl;
    system("PAUSE");
    return 0;
}
