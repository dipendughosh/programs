#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

struct vehicle
{   int number;
    char model[10];
};// car[2];

void getcar(vehicle c)//,int x )
{   cout<<"\nModel name : "; cin>>c.model;
    cout<<"Number     : "; cin>>c.number;
}

/*void showcar(vehicle d[],int y)
{   cout<<"\nCar "<<y+1;
    cout<<"\nName     : "<<d[y].model;
    cout<<"\nNumber   : "<<d[y].number;
    cout<<endl;
}*/
void showcar(vehicle[],int);
void main()
{   vehicle car[2];
    for ( int i=0; i<2; i++ )
    {   cout<<"\nCar No. "<<i+1;
        cout<<"\nModel name : "; cin>>car[i].model;
        cout<<"Number     : "; cin>>car[i].number;
    //    getcar(car);//[i]);//,i);
    }
    getche();

    cout<<"\nDISPLAYING THE CAR-DETAILS\n";
    for ( int j=0; j<2; j++ )
        //showcar(car,j);
        {   cout<<"\nCar Name : "<<car[j].model;
            cout<<"\nNumber   : "<<car[j].number;
            cout<<endl;
        }
        getche();
}

void showcar(vehicle d[],int y)
{   cout<<"\nCar Name : "<<d[y].model;
    cout<<"\nNumber   : "<<d[y].number;
    cout<<endl;
}
