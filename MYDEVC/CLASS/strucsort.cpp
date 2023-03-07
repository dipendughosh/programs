#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
struct date
{   int day;
    int month;
    int year;
};
struct employee
{   int empno;
    char name[30];
    int pay;
    date dob;
    date doj;
};

int main()
{   employee emp[3];
    int ch;
    void sort(employee emp[3],int), show(employee emp[3]);
    for(int i = 0; i < 3; i++)
    {   cout<<"\nEmployee no. : "; cin>>emp[i].empno;
        cout<<"          Name : "; gets(emp[i].name);
        cout<<"\n         Pay : "; cin>>emp[i].pay;
        cout<<"Date of birth   :- ";
        cout<<"\n         Day : "; cin>>emp[i].dob.day;
        cout<<"\n       Month : "; cin>>emp[i].dob.month;
        cout<<"\n        Year : "; cin>>emp[i].dob.year;
        cout<<"Date of Joining :- ";
        cout<<"\n         Day : "; cin>>emp[i].doj.day;
        cout<<"\n       Month : "; cin>>emp[i].doj.month;
        cout<<"\n        Year : "; cin>>emp[i].doj.year;
    }
    cout<<"\nIn which order you want to view ? \n";
    cout<<"\n1.Alphabet";
    cout<<"\n2.Pay";
    cout<<"\n3.Date of Birth";
    cout<<"\n4.Date of Joining";
    cout<<"\n0.Exit\n";
    cout<<"\nEnter your choice - "; cin>>ch;
    switch(ch)
    {   case 'A' : case 1 : sort(emp,ch); break;
        case 'P' : case 2 : sort(emp,ch); break;
        case 'B' : case 3 : sort(emp,ch); break;
        case 'J' : case 4 : sort(emp,ch); break;
        case 'X' : case 0 : exit(0); break;
    }
    show(emp);
    cout<<endl;
    system("PAUSE");
    return 0;
}

void sort(employee staff[],int n)
{   struct employee temp;
    for(int x = 0; x < 3; x++)
    {   for(int y = 0; y < 3; y++)
        {   int flag = 0;
            switch(n)
            {   case 1 :
                    if(strcmp(staff[x].name, staff[y].name) <= 0)
                        flag = 1;
                    break;
                case 2 :
                    if(staff[x].pay < staff[y].pay)
                        flag = 1;
                    break;
            }
            if(flag)
            {   temp = staff[x];
                staff[x] = staff[y];
                staff[y] = temp;
            }
        }
    }
}

void show(employee staff[])
{   cout<<"\n\nE.No.\tName\tPay\tDOB\tDOJ\n";
    for(int x = 0; x < 3; x++)
    {   cout<<"\n"<<staff[x].empno<<"\t"
            <<staff[x].name<<"\t"
            <<staff[x].pay<<"\t"
            <<staff[x].dob.day<<"/"
            <<staff[x].dob.month<<"/"
            <<staff[x].dob.year<<"\t"
            <<staff[x].doj.day<<"/"
            <<staff[x].doj.month<<"/"
            <<staff[x].doj.year;
    }
}
