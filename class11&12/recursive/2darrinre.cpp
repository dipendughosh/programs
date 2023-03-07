#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[5][5],r=0,c=0;

void main()
{	
    cout<<"\nEnter elements of array->\n";
    void input(int [5][5], int , int );
    input (a , r , c); 
    void print(int [5][5], int , int );
    print (a , r , c);
    cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
	

}

void input( int a[5][5], int r, int c)
{    if(c<=4)
     {   cin>>a[r][c];
         c++;
     }
     else
     {   r++;
         c=0;
         if(r==5)
         {    return ;
         }
     }
     input (a , r , c); 
}   

void print( int a[5][5], int r, int c)
{    if(c<=4)
     {   cout<<a[r][c]<<"\t";
         c++;
     }
     else
     {   r++;
         c=0;
         cout<<"\n";
         if(r==5)
         {    return ;
         }
     }
     print (a , r , c); 
}   
