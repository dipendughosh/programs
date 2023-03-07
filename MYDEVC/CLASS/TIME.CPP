#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class train
{       int h,m,s;
        long total;
    public:
        train()
        {   total=0;
        }
        void input()
        {
            cin>>h>>m>>s;
        }

        friend void calc(time,time);


}o1,o2;


void calc(time t1,time t2)
{   if (t1.h==t2.h)
    {   if (t1.m==t2.m)
        {   if (t1.s==t2.s) cout<<"\nWrong input.";
            else total+=t2.s-t1.s;
        }
        else total+=(t2.m-t1.m)*60;
    }
    else
    {   if (t2.h<t1.h) t2.h+=24;
        //SECONDS CHECK
        if (t2.s<t1.s)
        {   t2.s+=60;
            if (t2.m==0)
            {   t2.m=59;
                t2.h--;
            }
            else
            {   t2.m--;
            }
        }
        //MINUTES CHECK



        total+=(t2.h-t1.h)*3600+



int main()
{   cout<<"Enter the departure time (24 hour format)... ";
    o1.input();
    cout<<"\nEnter the arrival time at DEo1.sTINATION(24 hour format)...";
    o2.input();
    cout<<endl;
    system("PAUSE");
    return 0;
}
