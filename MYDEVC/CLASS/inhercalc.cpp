#include <iostream.h>
#include <stdlib.h>
class number
{     int a,b;
      public:
        double c;
        void getdata()
        {    cout<<"Enter no. 1 : "; cin>>a;
             cout<<"Enter no. 2 : "; cin>>b;
        }
};
class add
{     int t;
      public:
        int docalc(int p,int q)
        {   t=p+q;
            return t;
        }
};
class subs
{     int t;
      public:
      int docalc(int p,int q)
      {   if(p>=q) t=p-q;
          else t=q-p;
          return t;
      }
};
class mult
{     long t;
      public:
      long docalc(int p,int q)
      {   t=(p*q);
          return t;
      }
};
class div
{     float t;
      public:
      double docalc(int p,int q)
      {   if(p>=q) t=p/q;
          else t=q/p;
          return t;
      }
};

class takethird : public number,public add,
                  public subs,public mult,public div
{
      private:
        int n,result;
        char ch;
      public:
        void getdata()
          {
               c = 0.0;
               number::getdata();
               cout<<"\n   MENU\n";
               cout<<"a. Add\n"<<"s. Subtract\n"<<"m. Multiply\n"<<"d. Divide";
               cout<<"\nWhat to do (a/s/m/d) : "; cin>>ch;
               switch(ch)
               {    case 'a':
                        c = add ::docalc(a,b); break;
                    case 's':
                        c = subs::docalc(a,b); break;
                    case 'm':
                        c = mult::docalc(a,b); break;
                    case 'd':
                        c = div ::docalc(a,b); break;
                    default :
                        cout<<"Wrong choice ";
               }
               cout<<"\nThe result is : "<<c;
          }
};

int main()
{   takethird num;
    num.getdata();
    cout<<endl;
    system("PAUSE");
    return 0;
}
