#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

struct stu
{   char name[50];
    int phy;
    int chem;
    int math;
    int comp;
    int total;
    float average;
}
student[3];

int main()
{  int i,j;
   for(i=0;i<3;i++)
    {   cout<<"Enter name of student : ";
        gets(student[i].name);
        cout<<"Enter marks of physics : ";
        cin>>student[i].phy;
        cout<<"Enter marks of chemistry : ";
        cin>>student[i].chem;
        cout<<"Enter marks of maths : ";
        cin>>student[i].math;
        cout<<"Enter marks of computer : ";
        cin>>student[i].comp;
        student[i].total =  student[i].phy+student[i].chem+student[i].math+student[i].comp;
        student[i].average = student[i].total / 4;
    }
    stu temp;
    for(i = 0; i < 2; i++)
    {   for(j = i+1; j < 3; j++)
        {   if(student[i].total <= student[j].total)
            {   temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }
    cout<<"\n\n\n";
    for(i=0;i<3;i++)
    {   cout<<"\nName of student : ";
        puts(student[i].name);
        cout<<"\t"<<student[i].phy;
        cout<<"\t"<<student[i].chem;
        cout<<"\t"<<student[i].math;
        cout<<"\t"<<student[i].comp;
        cout<<"\nTotal : "<<student[i].total;
        cout<<"\tAverage : "<<student[i].average;
        cout<<endl;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
