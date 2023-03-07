#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    int daysInMon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int dob,mob,yob;
    int curday,curmon,curyear;
    int ageday = 0,agemon = 0 ,ageyear = 0;
    int day,month,year,dinmon;
    int checkleap(int);
    cout<<"Enter current date \n";
    cout<<"Day : "; cin>>curday;
    cout<<"Month : "; cin>>curmon;
    cout<<"Year : "; cin>>curyear;
    cout<<"Enter Date in question \n";
    cout<<"Day : "; cin>>dob;
    cout<<"Month : "; cin>>mob;
    cout<<"Year : "; cin>>yob;
    day = dob;
    dinmon = (mob == 2 ? checkleap(yob): daysInMon[mob]);
    month = mob;
    year = yob;
    do
    {
        ageday++; day++;
/*cout<<"\nday = "<<day<<"/"<<month<<"/"<<year;
cout<<"\tage = "<<ageday<<"/"<<agemon<<"/"<<ageyear;*/
        if (day > dinmon)
        {   day = 1;
            month = (month == 12 ? 1 : ++month);
            year = (month == 1 ? ++year : year);
            dinmon = (month == 2 ? checkleap(year): daysInMon[month]);
/*cout<<"\nday2 = "<<day<<"/"<<month<<"/"<<year;*/
        }
        if (ageday > 30)
        {   ageday = 1;
            agemon = (agemon == 12 ? 1 : ++agemon);
            ageyear = (agemon == 1 ? ++ageyear : ageyear);
//cout<<"\nday3 = "<<day<<"/"<<month<<"/"<<year;
        }
    }
    while(day != curday || month != curmon || year != curyear);
    cout<<"\nThe age is : "<<ageyear<<" Years "
        <<agemon<<" Months "<<ageday<<" Days";
    cout<<endl;
    system("PAUSE");
    return 0;
}

int checkleap(int y)
{
    if(y/4)
    {   if(y/100)
        {   if(y/400) return 29;
            else return 28;
        }
    }
    else
        return 28;
}

