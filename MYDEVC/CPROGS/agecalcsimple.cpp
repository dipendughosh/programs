// Age calculation where month = 30 days by default

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int dob,mob,yob,curday,curmon,curyear;
    int agemon = 0,ageday = 0, ageyear = 0;
    cout<<"Enter date of birth : \n";
    cout<<"Day   : "; cin>>dob;
    cout<<"Month : "; cin>>mob;
    cout<<"Year  : "; cin>>yob;
    cout<<"\nEnter current date : \n";
    cout<<"Day   : "; cin>>curday;
    cout<<"Month : "; cin>>curmon;
    cout<<"Year  : "; cin>>curyear;
    if(curday < dob)
    {   curday += 30;
        curmon--;
    }
    ageday = curday - dob;
    if(curmon < mob)
    {   curmon += 12;
        curyear--;
    }
    agemon = curmon - mob;
    ageyear = curyear - yob;
    cout<<"\nThe age is :\n";
    cout<<ageyear<<" Years "<<agemon<<" months "<<ageday<<" days.";
    cout<<endl;
    system("PAUSE");
    return 0;
}
