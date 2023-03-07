/*A PROGRAM OF 8-QUEEN'S PROBLEM*/
#include<stdio.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0
#define SIZE 10
int x[8];
int good(int row)
{
int i;
for(i=0;i<row;++i)
if(x[i]==x[row]||i-row==(x[i]-x[row])||i-row==-(x[i]-x[row]))
return (FALSE);
return(TRUE);
}
int try(int row)
{
int i;
for(i=0;i<8;i++)
{
x[row]=1;
if(row==7 && good(row)==TRUE)
return(TRUE);
if(row<7 && good(row)==TRUE && try(row+1)==TRUE)
return(TRUE);
x[row]=-1;
}
return(FALSE);
}
void drawboard()
{
int i,j;
printf("\n The solution to the 8-queen's problem is..\n\n");
printf("                 -------------------------------\n");
printf("                 1   2   3   4   5   6   7   8    \n");
printf("		 -------------------------------\n");
for(i=0;i<8;i++)
{
printf("\n");
printf("      %d      ",j+1);
for(j=0;j<8;++j)
if(j==x[i])
printf("   1  ");
else
printf("   0  ");
}
printf("\n\n");
}
void main()
{
if(try(0))
drawboard();
getch();
}