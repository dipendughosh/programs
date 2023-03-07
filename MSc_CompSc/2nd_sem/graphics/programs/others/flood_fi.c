
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "conio.h"
#include "dos.h"


int fillme(int x,int y,int fill,int boundry);

union REGS in,out;
void draw_diagram();
void Get_Input();

int current;
/*This module try to detect the mouse driver and initialize it*/
void detectmouse()
{
  in.x.ax=0;
  int86(0x33,&in,&out);
  if(out.x.ax==0)
   outtextxy(getmaxx()/2,getmaxy()/2,"Unable to initializ mouse...");

   //outtextxy(getmaxx()/2,getmaxy()/2,"Mouse initialized...");
}
/*End of driver detection and initialization*/



/*This module shows the mouse cursor on the screen*/
void showmouse()
{
  in.x.ax=1;
  int86(0x33,&in,&out);
}
void showmousegraphics()
{
  in.x.ax=1;
  int86(0x33,&in,&out);
}

void detect_click(int *click_x,int *click_y)
{
  //int gdriver=DETECT,gmode,errorcode;
  //initgraph(&gdriver,&gmode,"E:\\tc\\bin\\");
  int x,y;
  char *msg;
  in.x.ax=3;

  while(kbhit()==0)
  {


    int86(0x33,&in,& out);

    if(out.x.bx==1)
    {
      x=out.x.cx;
      y=out.x.dx;
      //putpixel(x,y,GREEN);
      sprintf(msg,"Left click...");
      //outtextxy(getmaxx()/2,getmaxy()/2+scale,msg);
      sprintf(msg,"Click co - ordinate: (%d , %d)",x,y);
      //outtextxy(getmaxx()/2,getmaxy()/2+2*scale,msg);
      *click_x=x;
      *click_y=y;

      break;


    /*
    if(out.x.bx==2) outtextxy(getmaxx()/2,getmaxy()/2+scale,"Right click..");
    if(out.x.bx==3) outtextxy(getmaxx()/2,getmaxy()/2+scale,"Middle click..");
    */
  }
  }

}


int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int maxy,maxx,click_x,click_y;
   int *poly;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   maxx = getmaxx();
   maxy = getmaxy();

   poly[0] = 20;        /* 1st vertext */
   poly[1] = maxy / 2;

   poly[2] = maxx - 20; /* 2nd */
   poly[3] = 20;

   poly[4] = maxx - 50; /* 3rd */
   poly[5] = maxy - 20;

   poly[6] = maxx / 2;  /* 4th */
   poly[7] = maxy / 2;
/*
   drawpoly doesn't automatically close
   the polygon, so we close it.
*/
   poly[8] = poly[0];
   poly[9] = poly[1];

   /* draw the polygon */
   setcolor(GREEN);
   //drawpoly(5, poly);
   rectangle(getmaxx()/2,getmaxy()/2,getmaxx()/2+10*textheight("S"),getmaxy()/2+10*textheight("S"));
   setcolor(RED);
   detectmouse();

   showmousegraphics();

   detect_click(&click_x,&click_y);
   fillme(click_x,click_y,RED,GREEN);


   getch();
   closegraph();
   return 0;
}

int fillme(int x,int y,int fill,int boundry)
{

   current=getpixel(x,y);


   if((current!=GREEN)&&(current!=RED))
   {
     setcolor(fill);
     putpixel(x,y,RED);

     fillme(x+1,y,RED,GREEN);

     fillme(x-1,y,RED,GREEN);

     fillme(x,y+1,RED,GREEN);

     fillme(x,y-1,RED,GREEN);


     return 1;

   }
   else
     return 0;
}
