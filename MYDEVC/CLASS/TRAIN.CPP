//dep. time from howrah in 24-hr format
//arrival time at each destinations in 24-hr format
//display the destination arrival time in 12-hr format & total time taken
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class train
{       int h,m,s,sh,sm,ss;
        long total;
    public:
        train()
        {   total=0;
        }
        void input()
        {   cout<<"Enter the departure time (24 hour format)... ";
            cin>>h>>m>>s;
            for(int i=0;i<4;i++)
            {   cout<<"\nEnter the arrival time at STATION(24 hour format) "<<i+1<<"...";
                cin>>sh>>sm>>ss;
                if (sh-h==0)
                {   if (sm-m==0)
                    {   if (ss-s==0) cout<<"\nWrong input.";
                        else total+=ss;
                    }
                    else total+=sm*60+ss;
                }
                else total+=sh*3600+sm*60+ss;
                h=sh;
                m=sm;
                s=ss;
            }
        }
        void timecalc()
        {





int main()
{
    cout<<endl;
    system("PAUSE");
    return 0;
}
