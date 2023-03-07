// Frequency and highest requent Mark

#include <iostream.h>
#include <conio.h>

class performance
{   int mark[],mode,frequatmode;
    public:
        performance()              // Constructor
            {   mode = 0; frequatmode = 0;  }
        void readmarks();
        int getmode();
        int getfreqatmode();
        void calcmodeandfrequency();
};                                  // Class definition complete

// *********** Methods ***********

void performance::readmarks()
{   cout<<"Enter the marks :\n";
    for(int i = 0; i<6; i++)
    {   do
        {   cin>>mark[i];
        } while(mark[i]<1 || mark[i]>100);
    }
}

int performance::getmode()
{   int freq = 0, highfreq = 0, highmode = 0;
    for(int i = 0; i<6; i++)
    {    for(int j=0; j<6; j++)    // Searching within the array
            if(mark[i] == mark[j]) freq++;
         if(freq == highfreq)
            highmode = highmode>mark[i] ? highmode : mark[i];
         else if(freq>highfreq)
         {   highfreq = freq;
             highmode = mark[i];
         }
         freq = 0;
    }
    return highmode;
}

int performance::getfreqatmode()
{   int freq = 0, highfreq = 0, highmode = 0;
    for(int i = 0; i<6; i++)
    {    for(int j=0; j<6; j++)
             if(mark[i] == mark[j]) freq++;
         if(freq>highfreq) highfreq = freq;
         freq = 0;
    }
    return highfreq;
}

void performance::calcmodeandfrequency()
{   int freq = 0, highfreq = 0, highmode = 0;
    for(int i = 0; i<6; i++)
    {    for(int j=0; j<6; j++)
            if(mark[i] == mark[j]) freq++;
         if(freq == highfreq)
            highmode = highmode>mark[i] ? highmode : mark[i];
         else if(freq>highfreq)
         {   highfreq = freq;
             highmode = mark[i];
         }
         freq = 0;
    }
    cout<<"\nHighest frequency is     : "<< highfreq;
    cout<<"\nHighest frequent mark is : "<< highmode;
}

//*************** Main ( Not needed in the problem )

void main()
{   performance result;
    result.readmarks();
    cout<<"\nMode : "<<result.getmode()<<endl;
    cout<<"\nFrequancy : "<<result.getfreqatmode()<<endl;
    //getche();
    result.calcmodeandfrequency();
    getche();
}

/*   Since calcmodeandfrequency() is a void function, it will NOT
   return a value. Hence, care should be taken to display the
   output within the function. */



