#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "process.h"
void main(void)
{
int i,n;
char str[100];
clrscr();
printf("\n Enter  a  word:->\n\n \t  ");
gotoxy(10,20);
gets(str);
n=strlen(str);
for(i=0;i<n/2;i++);
{
 if(str[i]!=str[n-i-1])
  {
   gotoxy(20,22);
   printf("\nSorry,the word you have entered is not palindro!!");

   exit(0);
  }
}
printf( "\nThe word you have entered is palindrom");
gotoxy(30,22);
printf("\n Press any key to exit... ...");
getch();
}