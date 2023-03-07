#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
   int vote[5], spoil = 0, number;
   for(int i = 0; i < 5; i++) vote[i]=0;
   do
   {
        cout<<"Enter choice : " ; cin >> number;
        if(number > 5)
        {   cout<<"\nBallot spoiled!\n";
            spoil++;
        }
       switch(number)
       {   case 1 : vote[0]++;
                break;
            case 2 : vote[1]++;
                break;
            case 3 : vote[2]++;
                break;
            case 4 : vote[3]++;
                break;
            case 5 : vote[4]++;
                break;
          //  default:
            //    spoil++;
       }
       //vote[number-1]++;
       //if(number == 2) break;
    }
    while(number);
    for(int i = 0; i < 5; i++)
       cout<<"\nVote for candidate "<<(i+1)<<" : "<<vote[i];
    cout<<"\n                    Spoiled Votes :"<<spoil;
    cout<<endl;
    system("PAUSE");
    return 0;
}
