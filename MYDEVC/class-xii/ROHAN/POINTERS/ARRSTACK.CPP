#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<ctype.h>
#include<process.h>
int cal(int x,int y,char s)
{
    switch (s)
    {
	     case '+':
		  return (y+x);
	     case '-':
		  return (y-x);
	     case '*':
		  return (y*x);
	     case '/':
		  return (y/x);
	     //case '^':
	     //     return ((int)(pow(y,x));break;
	     //default :
		//return 0;
     }
}
int main()
{
	  //clrscr();
	  char exp[10];
	  int stack[10];
	  cout<<"\nEnter data...";gets(exp);
	  int i=0,top=-1,x,y;
	  while(exp[i]!='\0')
	  {
	      if(isdigit(exp[i]))
	      {
		    stack[++top]=(int)(exp[i])-48;
		    //cout<<stack[top];getch();
	      }
	      else
	      {
		  //x=stack[top];
		  //--top;
		  //y=stack[top];
	  //cout<<"\nStack top.."<<stack[top]<<"\t Second last..."<<stack[top-1];
	  //getch();
	  cout<<stack[top]<<"\t"<<stack[top-1];

		  stack[top-1]=cal(stack[top-1],stack[top],exp[i]);
		  //cout<<"\nStack top.."<<stack[top]<<"\t Second last..."<<stack[top-1];
		  //getch();
	  cout<<"\nCal Value..."<<cal(stack[top-1],stack[top],exp[i]);getch();
		  --top;//cout<<stack[top];getch();

	       }
	       i++;
	   }
	   cout<<"top"<<top;
	   cout<<"\n Answer is....";stack[top];
	   getche();
	   return 0;
}




     