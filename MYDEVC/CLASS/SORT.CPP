#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include<stdio.h>

class num
{
         int r, m;
         public:
         void getdata();
         void putdata();
         void arrange(int,int);
}stu[5];
     void num::getdata()
    {  cout<<"\n roll , no";
            cin>>r;
                              // for(int i=0;i<3;i++)
            cin>>m;
    }
  void main()
  {
        int i,j;
         for( i=0;i<5;i++)
              stu[i].getdata();
         for(i=0;i<5;i++)
                stu[i].putdata();
         for(i=0;i<4;i++)
         {  for(j=i+1;j<5;j++)
                 stu[i].arrange(i,j);
         }
         for(i=0;i<5;i++)
         stu[i].putdata();

 getche();
 return 0;
 }

              void num::arrange(int a,int b)
              {   if (m>m)
                    int temp1,temp2;
                    temp1=r[b];r[b]=r[a];r[a]=temp1 ;
                     temp2=m[b];m[b]=m[a];m[a]=temp2;
              }


              void num::putdata()
           {
                cout<<endl<<"marks"<<m[i];
                cout<<endl<<"roll"<<r[i];
           }

