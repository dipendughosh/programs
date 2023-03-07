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
        void arrange(student[]);
};
void student::getdata()
{   cout<<"Enter Roll : "; cin>>roll;
    cout<<"Enter Marks : "; cin>>marks;
}
void student::showdata()
{   cout<<"Roll is : "<<roll<<"\t";
    cout<<"Marks is : "<<marks;
}

void student::arrange(student s[])
{   student temp;
    for(int i=0;i<3;i++)
    {   for (int j=i;j<4;j++)
        {   if (s[i].marks<s[j].marks)
            {   temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
         }
    }
}

int main()
{
    student stu[4],temp;
    for(int i = 0; i < 4; i++)
    {
        stu[i].getdata();
    }
    stu[0].arrange(stu);
/*    for(int x = 0; x < 4; x++)
    {
        for(int y = x+1; y < 4; y++)
        {
            if(stu[x].marks < stu[y].marks)
            {
                temp = stu[x];
                stu[x] = stu[y];
                stu[y] = temp;
            }
        }
    }*/
    for (int p = 0; p < 4; p++)
    {    stu[p].showdata();
         cout<<endl;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}



