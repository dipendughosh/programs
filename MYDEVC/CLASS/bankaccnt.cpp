#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
class account
{     private:
      int acno;
      char name[20];
      public:
      int balance,interest;
      void getdata()
      {    cout<<"\nAccount Number   : "; cin>>acno;
           cout<<"Name of Subscriber : "; gets(name);
           cout<<"\nOpening Balance    : "; cin>>balance;
      }
      void showdata()
      {    cout<<"\nName           : "<<name;
           cout<<"\nAccount Number : "<<acno;
           cout<<"\nBalance         : "<<balance;
      }
};
class current:public account
{     int deposit,withdraw,penalint;
      public:
      current()
      { deposit = 0;
        withdraw = 0;
        penalint = 0;
      }
      void credit()
      {    cout<<"\nDeposit : "; cin>>deposit;
      }
      void debit()
      {    cout<<"\nExisting Balance : "<<balance;
           cout<<"\nWithdrawal       : "; cin>>withdraw;
           if (withdraw > balance)
              penalint = (balance - withdraw)*.05;
      }
      void intcal()
      {    balance=balance+deposit-withdraw;
           interest=(balance*.05) + penalint;
           balance+=interest;
           account::showdata();
      }
      /*void showdata()
      {    account::showdata();
           cout<<"\nDeposit : "<<deposit;
      } */
};
class savings:public account
{     int deposit,withdraw;
      public:
      void credit()
      {    cout<<"\nDeposit : "; cin>>deposit;
      }
      void debit()
      {    cout<<"\nExisting Balance : "<<balance;
           cout<<"\nWithdrawal       : "; cin>>withdraw;
           if (withdraw > balance)
           {  cout<<"Sorry! Insufficient Balance";
              withdraw = 0;
           }
      }
      void showdata()
      {    account::showdata();
           cout<<"\nWithdrawal : "<<withdraw;
      }
};

class trans:public current,public savings
{     char actype,trantype;
      public:
      void transaction()
      {    current::getdata();
           cout<<"\nEnter Type of Account(s/c)  : "; cin>>actype;
           cout<<"Type of transaction (c/d) : "; cin>>trantype;
           if (actype == 'c')
           {  if (trantype == 'c') current::credit();
              else current::debit();
           }
           else
           {   if (trantype == 'c') savings::credit();
               else savings::debit();
           }
           current::intcal();
           //savings::showdata();
        }
};
int main()
{   trans subs;
    subs.transaction();
    cout<<endl;
    system("PAUSE");
     return 0;
}
