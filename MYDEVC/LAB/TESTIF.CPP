#include <iostream.h>
#include <stdlib.h>
//#include <conio.h>

void main()
{   int day;
    cout<<"\nEnter day-number : "; cin>>day;
    switch(day)
    {   case 2 : cout<<"\nMon"; break;
        case 1 : cout<<"\nSun"; break;
        case 3 : cout<<"\nTue"; break;

        default : cout<<"\nNo such day";
    }
    cout<<endl;
    system("PAUSE");
}
