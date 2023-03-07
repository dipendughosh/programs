#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
//#include <stdio.h>


int main()
{
    int units, metrent = 50;
    float rate, bill = 0;
    cout << " Input Units : "; cin >> units;
    for(int ctr = 1; ctr <= units; ctr++)
    {
        if(ctr <= 100) rate = 0.4;
        else if(ctr <= 300) rate = 0.5;
        else rate = 0.6;
        bill += rate;
    }
    //clrscr();
    cout<<"\n\t****** ELECTRIC BILL *********" << endl;
    cout << "\n\n\t Units consumed : " << units << endl;
    cout << "\n Charge     : Rs." << bill;
    cout << "\n Meter Rent : Rs." << metrent;
    bill += metrent;
    cout << "\n\n\t Total Bill : Rs." << bill<<endl;
    cout<<endl;
    system("PAUSE");
    return 0;
}


