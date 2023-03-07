#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int daysInMon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int checkLeap(int);
    int dob,mob,yob,day,month,year,curday,curmon,curyear;
    int agemon = 0,ageday = 0, ageyear = 0;
    int dinmon = 0,dim=0,ctr = 0;
    cout<<"Enter date of birth : \n";
    cout<<"Day   : "; cin>>dob;
    cout<<"Month : "; cin>>mob;
    cout<<"Year  : "; cin>>yob;
    cout<<"\nEnter current date : \n";
    cout<<"Day   : "; cin>>curday;
    cout<<"Month : "; cin>>curmon;
    cout<<"Year  : "; cin>>curyear;
    day = dob;
    month = mob;
    year = yob;
    dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);
    do
    {
        ++day; ++ctr;
        if(day > dinmon )
        {
            ++month; day = 1;  // Month increases after dinmon
            if(month > 12)
            {
                ++year; month = 1;
            }
            dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);
        }
    }
    while(day != curday || month != curmon || year != curyear);
    day = dob;
    month = mob;
    year = yob;
    dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);
    int i = 0;
    do
    {   ++ageday;
        if(ageday > dinmon )
        {
            ++month; ++agemon; ageday = 1;  // Month increases after dinmon
            if(month > 12)
            {
                ++year; month = 1;
            }
            if(agemon > 11)
            {
                ++ageyear; agemon = 0;
             }
            dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);
        }
        ++i;
    }
    while(i<ctr);
    cout<<"\nAge is : ";
    cout<<ageyear<<" Years "<<agemon<<" Months "<<ageday<<" Days.";
    cout<<endl;
    system("PAUSE");
    return 0;
}

int checkLeap(int y)
{
    if(y % 4)
    {   if(y % 100)
        {   if(y % 400) return 29;
            else return 28;
        }
        return 29;
    }
    return 28;
}

