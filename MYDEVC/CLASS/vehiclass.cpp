#include <iostream.h>
#include <conio.h>
//#include <stdlib.h>

class vehicle
{   private :
        int number;
        char model[10];
    public :
        void getcar()
        {   cout<<"\nModel name : "; cin>>model;
            cout<<"Number     : "; cin>>number;
        }
        void showcar();
};
//vehicle car[4];
void vehicle::showcar()//(char m[],int n)
{   cout<<"\nCar Name : "<<model;
    cout<<"\nNumber   : "<<number;
    cout<<endl;
}
//vehicle car[4];
int main()
{   vehicle car[4];
    for ( int i=0; i<4; i++ )
    {   cout<<"\nCar No. "<<i+1;
        car[i].getcar();
    }
    getche();
    cout<<"/nDISPLAYING THE CAR-DETAILS/n";
    for ( int j=0; j<4; j++ )
        car[j].showcar();

    getche();
    return 0;
}
