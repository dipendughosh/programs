#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class student
{   private:
        int roll;
        int marks;
    public:
        void getdata();
        void showdata();
};

void student::getdata()
{   cout<<"Enter Roll : "; cin>>roll;
    cout<<"Enter Marks : "; cin>>marks;
}
void student::showdata()
{   cout<<"Roll is : "<<roll<<"\t";
    cout<<"Marks is : "<<marks;
}

int main()
{   student stu[4];
    for(int i=0;i<4;i++)//student stu;
        stu[i].getdata();
    cout<<endl;
    for(int j=0;j<4;j++)//student stu;
        stu[j].showdata();
    cout<<endl;
    system("PAUSE");
    return 0;
}
