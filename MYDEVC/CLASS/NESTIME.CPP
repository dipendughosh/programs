// Nested class

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class time
{   private:
        int hr, min, sec;
        class present
        {   int hr, min, sec;
            present()
            {   cout<<"Present hour    : "; cin>>hr;
                cout<<"Present minutes : "; cin>>min;
                cout<<"Present seconds : "; cin>>sec;
            }
            int convpt()
            {   int m = min + (hr * 60);
                int s = sec + (m * 60);
                return s;
            }
        };
    public:
        time()
        {   cout<<"Default hour    : "; cin>>hr;
            cout<<"Default minutes : "; cin>>min;
            cout<<"Default seconds : "; cin>>sec;
            cout<<endl;
            present ptobj;
            cout<<"\nPresent seconds : "<<ptobj.convpt();
        }
        int convtime()
        {   int m = min + (hr * 60);
            int s = sec + (m * 60);
            return s;
        }
        int difftime()
        {   int diff = convtime() - ptobj.convpt();
            return diff;
        }
};

int main()
{   time tt;
    tt.convtime();
    cout<<"\nDifference : "<< tt.difftime();
    cout<<endl;
    system("PAUSE");
    return 0;
}
