// Counting days from a given date

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int daysinmon[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int day, mon, year, curday = 1, curmon = 1, curyear = 2005;
    int error = 1, dayno = 0;
    bool isleap(int);
    do
    {
        cout << "Enter year  : "; cin >> year;
        if(year < curyear)
        {   cout << "Invalid input. Try again... ";
            continue;
        }
        cout << "Enter month : "; cin >> mon;
        if(year == curyear && mon < curmon)
        {   cout << "Invalid input. Try again... ";
            continue;
        }
        if(mon < 0 || mon > 12)
        {   cout << "Invalid input. Try again... ";
            continue;
        }
        if(mon == 2 && isleap(year)) daysinmon[2] = 29;
        cout << "Enter day   : "; cin >> day;
        if(day <= 0 || day > daysinmon[mon])
        {   cout << "Invalid input. Try again... ";
            continue;
        }
        error = 0;
    }
    while(error > 0);
    do
    {
        dayno++; curday++;
        if(curday > daysinmon[curmon])
        {   curmon++; curday = 1;
            if(curmon > 12)
            {   curyear++; curmon = 1; }
        }
    }
    while(curday != day || curmon != mon || curyear != year);
    cout << "\nDays passed : " << dayno;
    cout << "\n....Indeed, days are numbered!!\n";
    cout<<endl;
    system("PAUSE");
    return 0;
}

bool isleap(int yr)
{
    return yr % 4 == 0 && yr % 100 != 0 || yr % 400 == 0;
}
