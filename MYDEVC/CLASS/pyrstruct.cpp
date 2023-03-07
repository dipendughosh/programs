#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

struct num
{   int n[6];
}number[6];

void main()
{   void setdata(num[],int);
    void showdata(num[],int,int);
    for(int p=0;p<6;p++) setdata(number,p);
    for (int x=0;x<6;x++)
    {  for(int y=5;y>=1;y--) showdata(number,y,x);
       cout<<setw(3)<<0;
       for(int t=1;t<6;t++) showdata(number,t,x);
       cout<<endl;
    }
    getche();
}

void setdata(num no[],int s)
{   for (int i=0; i<6; i++)
       for (int j=0; j<6; j++)
       {   if (j>=s) no[s].n[j]=s;
           else no[s].n[j]=0;
       }
}

void showdata(num nos[],int a,int b)
{   if (number[a].n[b]!=0) cout<<setw(3)<<number[a].n[b];
    else cout<<"   ";
}

