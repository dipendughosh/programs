/*incomplete*/
#include <iostream.h>
#include <conio.h>
#include <string.h>
class time
{   private:
        int hrs,mins,secs;
        char suf[4];
    public:
        int tot_secs;
        void gettime(int h,int m,int s)
        {   hrs = h; mins = m; secs = s;
            tot_secs = (hrs * 60) + (mins * 60) + secs;
            strcpy(suf,"hrs");
        }
        void puttime(void)
        {   cout<<"The time is : "<<hrs<<";"<<mins<<";"<<secs<<" "<<suf<<"\n";
        }
        char* getsuf() { return suf; }
        friend void convert(time &t, char ch);
        friend void sum(time &t1,time &t2);

        void convert(time &t,char ch) // Friend function
        {
            switch(ch)
            {   case 'h' :
                    if (strcmp(t.suf,"hrs")!=0)
                    {   t.hrs = (t.hrs)>12 ? t.hrs : hrs+12;
                        strcpy(t.suf,"hrs");
                    }
                    cout<<"The time in hours is : "<<t.hrs<<";"
                        <<t.mins<<";"<<t.secs<<" "<<t.suf<<"\n";
                    break;
                case 'p' :
                    if (strcmp(t.suf,"hrs")==0)
                    {   t.hrs = (t.hrs)>12 ? t.hrs : hrs+12;
                        strcpy(t.suf,"hrs");
                    }
                    cout<<"The time in am/pm is : "<<t.hrs<<";"
                        <<t.mins<<";"<<t.secs<<" "<<t.suf<<"\n";
                    break;
                default :
                    cout<<"Wrong choice\n";
            };
        }
        void sum(time& t1,time& t2)    // Friend function
        {   int h,m,s,sq,mq;
            if (strcmp(t1.getsuf(),"pm")==0) convert(t1,'h');
            if (strcmp(t2.getsuf(),"pm")==0) convert(t2,'h');
            sq = (t1.secs + t2.secs) / 60;
             s = (t1.secs + t2.secs) % 60;
            mq = (sq + t1.mins + t2.mins) / 60;
             m = (sq + t1.secs + t2.secs) % 60;
             h = mq + t1.hrs + t2.hrs;
            if (h == 24) h = 0;
            cout<<"The Total time is : "<<h<<":"<<m<<":"<<s<<" hrs/n";
        }
};

int main()
{   time tm1,tm2;
    char ch;
    tm1.gettime(15,13,27);
    tm1.puttime();
    tm2.gettime(7,48,38);
    tm2.puttime();
    cout<<"\nEnter h [to convert in hour format]"
        <<"p [to convert in am/pm format]";
    cin>>ch;
    cout<<"\tConverted times are :\n"
        <<"Time 1 : ";
    convert(tm1,ch);
    convert(tm2,ch);
    sum(tm1,tm2);
    getche();
    return 0;
}
