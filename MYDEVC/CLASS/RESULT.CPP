// STORING RESULTS AND ARRANGING THEM

#include <iostream.h>
#include <conio.h>
#include<stdio.h>

class student{
      char name[30];
      float submarks[3];
      public:
      float totmarks;
      void getdata();
      //void procdata(); ** Sorting function should NOT be a member
      void result();     // because this function will sort the objects
      };
void student::getdata()
{    cout<<"\nName of Student : "; gets(name);
     cout<<"\n\tMarks :\n";
     for (int m=0; m<3; m++){
         cout<<"Subject "<<m+1<<" : "; cin>>submarks[m];
         totmarks+=submarks[m]; }
}
void student::result(){
     cout<<"\nName : "<<name;
     for(int y=0; y<3; y++)
             cout<<"\t"<<y+1<<" - "<<submarks[y]<<"\t";
     cout<<"\t"<<totmarks;
}
void procdata(student& p,student& q)
{   student temp;
    if(p.totmarks<q.totmarks)
    {   temp=p; p=q; q=temp; }
}
student stu[3];
int main()
{   void procdata(student&,student&);
    int i,j;
    for (i=0; i<3; i++) stu[i].getdata();
    for (i=0; i<3; i++) stu[i].result();
    for (i=0; i<3-1; i++)
        for (j=i+1; j<3; j++) procdata(stu[i],stu[j]);
    getche();
    cout<<"\n\nRESULTS ARRANGED ACCORDING TO TOTAL MARKS :\n";
    for (int j=0; j<3; j++) stu[j].result();
    getche();
    return 0;
}
