#include <iostream.h>
#include <stdlib.h>
#include<conio.h>
class student
{
    //protected :
        int roll;
    public:
        void getroll()
            {cout<<"Enter Roll no. : ";cin>>roll;}
        void putroll()
            {cout<<"Roll Number : "<<roll;}
};

class test:public student
{
    //protected:
        int m1,m2;
    public :
        void getmarks()
        {   student::getroll();
            cout<<"Enter marks of subject 1 : "; cin>>m1;
            cout<<"Enter marks of subject 2 : "; cin>>m2;
        }
        void showmarks()
        {   student::putroll;
            cout<<"\nSubject 1 : "<<m1;
            cout<<"\nSubject 2 : "<<m2;
        }
};

class result:public test
{
    //protected:
    int total;
    public:
        void display()
        {   test::getmarks();
            total=m1+m2;
            //putroll();
            cout<<"\nRESULT\n";
            test::showmarks();
            cout<<"\nTOTAL     : "<<total;
        }
};

void main()
{
    result obj;
    obj.display();
    getche();
}




