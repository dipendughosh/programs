/*Recursive program to find positive integer
  exponent of a given positive integer number*/
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>


void main()
{     //clrscr();
      int a,b,x;                    //declaring variables
      int exponent(int,int);        //protype of function
      cout<<"\nEnter number-->";    //entering number 
      cin>>a;
      cout<<"\nEnter power-->";     //entering power  
      cin>>b;
      x=exponent(a,b);              //calling function
      cout<<"\n"<<a<<"^"<<b<<"="<<x;
      getche();
}

int exponent(int a, int b)          //function to find exponentional value
{     if(b==0)                      //check   
              return 1;
      if(b==1)                      //check              
              return a;
      if(b>0)                       //check                                                                
              return a*exponent(a,b-1);//recursion
      return a;
}      