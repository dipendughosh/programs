#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int a;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi\\");


   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   putpixel(100,100,155);
   a=getpixel(100,100);
   putpixel(200,200,a);
   cout<<a;
   getch();
   closegraph();
   return 0;
}

