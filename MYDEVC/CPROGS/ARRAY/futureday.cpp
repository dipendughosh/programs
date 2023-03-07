/*** Goal-seek Future Day ***/

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int daysInMon[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };
    int checkleap(int);
    int days, curday = 20, curmon = 9, curyear = 2007;
    cout << "The current date is : "
         << curday << "/" << curmon << "/" << curyear << endl ;
    cout << "\nEnter no. of days ahead : "; cin >> days;
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

