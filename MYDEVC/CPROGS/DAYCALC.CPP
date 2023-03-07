/********* LEAP TOWARDS A NEW DAY ***********/

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int daysInMon[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };
    int checkleap(int);
    int days, curday, curmon, curyear, error = 1;
    cout << "Input a date\n";
    do
    {
        cout << "Enter year  : "; cin >> curyear;
        if(curyear <= 0)
        {   cout << "Invalid input. Try again... ";
            continue;
        }
        cout << "Enter month : "; cin >> curmon;
        if( curmon <= 0 || curmon > 12)
        {   cout << "Invalid input. Try again... ";
            continue;
        }
        if(curmon == 2) daysInMon[2] = checkleap(curyear);
        cout << "Enter day   : "; cin >> curday;
        if(curday <= 0 || curday > daysInMon[curmon])
        {   cout << "Invalid input. Try again... ";
            continue;
        }
        error = 0;
    }
    while(error > 0);
    cout << "\nThe current date is : "
         << curday << "/" << curmon << "/" << curyear << endl ;
    cout << "\nEnter no. of days to add : "; cin >> days;
    daysInMon[2] = checkleap(curyear);
    while(days > 0)
    {
        days--;
        curday++;
        if(curday > daysInMon[curmon])
        {   curday = 1; curmon++;
            if(curmon == 2) daysInMon[2] = checkleap(curyear);
            if(curmon == 13)
            {   curyear++; curmon = 1;  }
        }
    }
    cout << "\nThe projected date would be: "
         << curday << "/" << curmon << "/" << curyear << endl ;
    cout<<endl;
    system("PAUSE");
    return 0;
}

int checkleap(int yr)
{
    if(yr % 4 == 0)
    {   if(yr % 100 == 0)
        {   if(yr % 400 == 0) return 29;
            return 28;
        }
        return 29;
    }
    else
        return 28;
}
