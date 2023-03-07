/********************8-CHANNEL CHAISER USING PARALLEL PORT*******************/

#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<bios.h>


const int PORT=0x0378;//PORT ADDRESS OF PARALLEL PORT
long int glow_delay=0,glow_num=0;//VARIABLES USED FOR TIMING
int v=2,a=85,r=15,s=0,o,i,j,flag=0,flag1=0;  //AND SEQUENCING LEDs
char d[5],n[5],ch[2];	

union REGS regs;//FOR MOUSE CONTROL.
int x=50,y=200;//AS COORDINATES.
int x1,y1,k;//AS MOUSE POINTER'S COORDINATES

void initialise()//INITIALISE MOUSE & GRAPHICS.
 {
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");//THIRD ARGUMENT IS PATH OF EGAVGA.BGI FILE.

  regs.x.ax=0;//INITIALISE MOUSE.
  int86(0x33,&regs,&regs);

  outport(PORT,0);//CLEARS PORT.
 }


void showmouse()//SHOWS MOUSE ON SCREEN.
 {
  regs.x.ax=1;
  int86(0x33,&regs,&regs);
 }

void hidemouse()//HIDES MOUSE.INVOKED WHEN SOMETHING IS DISPLAYED.
 {
  regs.x.ax=2;
  int86(0x33,&regs,&regs);
 }

void clear()//CLEAR MAIN MENU
 {
  hidemouse();
  cleardevice();
 }

void readmouse()//READS COORDINATES OF MOUSE'S CURRENT POSITION.
 {
  regs.x.ax=3;
  int86(0x33,&regs,&regs);
  x1=regs.x.cx;//x1 CONTAINS X-COORDINATE.
  y1=regs.x.dx;//y1 CONTAINS Y-COORDINATE.
  k=regs.x.bx&1;//CHECKS FOR MOUSE'S LEFT-BUTTON CLICK.
 }


void menu()
 {
  clear();
  setcolor(2);
  rectangle(0,0,getmaxx(),getmaxy());
  line(0,100,getmaxx(),100);
  line(0,300,getmaxx(),300);
  line(getmaxx()/2,300,getmaxx()/2,getmaxy());
  setcolor(15);
  settextstyle(1,0,5);
  outtextxy(110,20,"8 CHANNEL CHAISER");
  setcolor(14);
  settextstyle(0,0,1);
  outtextxy(110,70,"****************************************************");
  setcolor(9);
  outtextxy(300,110,"STYLES");
  outtextxy(300,116,"------");
  outtextxy(140,310,"SETTINGS");
  outtextxy(140,316,"--------");
  outtextxy(420,310,"INSTRUCTIONS");
  outtextxy(420,316,"------------");
  setcolor(4);
  rectangle(70,140,170,160);
  rectangle(270,140,370,160);
  rectangle(470,140,570,160);
  rectangle(70,196,170,216);
  rectangle(270,196,370,216);
  rectangle(470,196,570,216);
  rectangle(70,252,170,272);
  rectangle(270,252,370,272);
  rectangle(470,252,570,272);
  setcolor(13);
  outtextxy(120,146,"1");
  outtextxy(320,146,"2");
  outtextxy(520,146,"3");
  outtextxy(120,202,"4");
  outtextxy(320,202,"5");
  outtextxy(520,202,"6");
  outtextxy(120,258,"7");
  outtextxy(320,258,"8");
  outtextxy(505,258,"EXIT");
  setcolor(15);
  outtextxy(340,360,"* CLICK A STYLE");
  showmouse();
 }



void click(int z)//CHECK FOR MOUSE CLICK.
 {
  while(k)
   {
    flag1=0;
    readmouse();
    while((inportb(0x3da)&8));
    while(!(inportb(0x3da)&8));
    if(!k)//'k' STORES ZERO IF A LEFT-BUTTON CLICK TAKES PLACE.
    {
     if(z!=9)
     {
      hidemouse();
      outtextxy(340,380,"* ENTER DELAY");
      outtextxy(100,356,"DELAY : ");
      gotoxy(21,23);
      gets(d);
      glow_delay=atol(d);
      outtextxy(340,400,"* ENTER NUMBER OF TIMES");
      outtextxy(100,388,"TIMES : ");
      gotoxy(21,25);
      gets(n);
      glow_num=atol(n);
      outtextxy(340,420,"* PRESS ENTER TO START");
      if(bioskey(0)!=7181)
	{
	 showmouse();
          menu();
	 break;
	}
      outtextxy(340,440,"* PRESS ANY KEY ONCE TO RETIRE");
      showmouse();
     }
     switch(z)
     {
      case 1:
	     do
	     {
	      for(i=1;i<=128;i=i*2)     //FOR STYLE 1
	       {
		outport(PORT,i);
		if(bioskey(1))//EXITS IF A KEY IS PRESSED
		   {
		   flag1=1;
		   break;
		   }
		delay(glow_delay);
	       }
	      glow_num--;
	     }while(glow_num>0);
	     if(flag1) gets(ch);
	     outport(PORT,0);
	     break;
      case 2:
	     do
	     {
	      i=0;v=1;  //STYLE 2
	      do
	      {
	       i=i+v;
	       v=v*2;
	       outport(PORT,i);
	       if(bioskey(1))//EXITS IF A KEY IS PRESSED
		 {
		  flag1=1;
		  break;
		 }
	       delay(glow_delay);
	      }while(i<=255);
	      glow_num--;
	      outport(PORT,0);
	     }while(glow_num>0);
	     outport(PORT,0);
	     if(flag1) gets(ch);
	     break;
      case 3:
	     do
	     {
	      i=0;v=1;            //STYLE 3
	      do
	      {
	       i=i+v;
	       outport(PORT,i);
	       v=v*2;
	       if(bioskey(1))//EXITS IF A KEY IS PRESSED
		  {
		   flag1=1;
		   break;
		  }
	       delay(glow_delay);
	       if(i==255)
		 {
		  o=128;
		  do
		  {
		   outport(PORT,i);
		   i=i-o;
		   o=o/2;
		   if(bioskey(1))//EXITS IF A KEY IS PRESSED
		     {
		      flag1=1;
		      break;
		     }
		   delay(glow_delay);
		  }while(i>=1);
		 }
	      }while(i<=255);
	      glow_num--;
	      outport(PORT,0);
	     }while(glow_num>0);
	     outport(PORT,0);
	     if(flag1) gets(ch);
	     break;
      case 4:
	     glow_num*=2;       //STYLE 4
	     do
	     {
	      if(a==170)
		a=85;
	      else if(a==85)
		a=170;
	      outport(PORT,a);
	      if(bioskey(1))//EXITS IF A KEY IS PRESSED
		{
		 flag1=1;
		 break;
		}
	      delay(glow_delay);
	      glow_num--;
	     }while(glow_num>0);
	     outport(PORT,0);
	     if(flag1) gets(ch);
	     break;
      case 5:
	     glow_num*=2;           //STYLE 5
	     do
	     {
	      if(r==240)
		r=15;
	      else if(r==15)
		r=240;
	      outport(PORT,r);
	      if(bioskey(1))//EXITS IF A KEY IS PRESSED
		{
		 flag1=1;
		 break;
		}
	      delay(glow_delay);
	      glow_num--;
	     }while(glow_num>0);
	     outport(PORT,0);
	     if(flag1) gets(ch);
	     break;
      case 6:
	     glow_num*=2;         //STYLE 6
	     do
	     {
	      if(s==255)
		s=0;
	      else if(s==0)
		s=255;
	      outport(PORT,s);
	      if(bioskey(1))//EXITS IF A KEY IS PRESSED
		{
		 flag1=1;
		 break;
		}
	      delay(glow_delay);
	      glow_num--;
	     }while(glow_num>0);
	     outport(PORT,0);
	     if(flag1) gets(ch);
	     break;
      case 7:                        //STYLE 7
	     do
	     {
	      j=0;
	      for(i=129;j<5;i=((i+(3*j))/2))
		 {
		  outport(PORT,i);
		  if(bioskey(1))//EXITS IF A KEY IS PRESSED
		    {
		     flag1=1;
		     break;
		    }
		  delay(glow_delay);
		  if(j==2)
		    j=4;
		  else
		  j++;
		 }
	      outport(PORT,0);
	      glow_num--;
	     }while(glow_num>0);
	     if(flag1) gets(ch);
	     break;
      case 8:                  //STYLE 8
	     do
	     {
	      for(i=3;i<=192;i=i*2)
		 {
		  outport(PORT,i);
		  if(bioskey(1))//EXITS IF A KEY IS PRESSED
		    {
		     flag1=1;
		     break;
		    }
		  delay(glow_delay);
		 }
	      glow_num--;
	      outport(PORT,0);
	     }while(glow_num>0);
	     outport(PORT,0);
	     if(flag1) gets(ch);
	     break;
      case 9:
	     {
	      closegraph();
	      exit(0);//EXITS FROM THE PROGRAM
	     }
     }
    flag=1;
    }
   }
  }


void coordinates()//CHECKS WHETHER MOUSE'S POINTER IS INSIDE
 {                //ANY OF THE RECTANGLES DRAWN.
  showmouse();    //IF INSIDE INVOKES FUNCTION 'click(int)'.
  while(1)
  {
   readmouse();
   if(((x1>70&&x1<170)&&y1>140)&&y1<160)
      {
       click(1);
       if(flag)
	  break;//GOES TO MAIN
      }
   if(((x1>270&&x1<370)&&y1>140)&&y1<160)
      {
       click(2);
       if(flag)
	  break;//GOES TO MAIN
      }
   if(((x1>470&&x1<570)&&y1>140)&&y1<160)
      {
       click(3);
       if(flag)
	  break;//GOES TO MAIN
      }
   if(((x1>70&&x1<170)&&y1>196)&&y1<216)
      {
       click(4);
       if(flag)
	  break;//GOES TO MAIN
      }
   if(((x1>270&&x1<370)&&y1>196)&&y1<216)
      {
       click(5);
       if(flag)
	  break;//GOES TO MAIN
      }
   if(((x1>470&&x1<570)&&y1>196)&&y1<216)
      {
       click(6);
       if(flag)
	  break;//GOES TO MAIN
      }
   if(((x1>70&&x1<170)&&y1>252)&&y1<272)
      {
       click(7);
       if(flag)
	  break;//GOES TO MAIN
      }
   if(((x1>270&&x1<370)&&y1>252)&&y1<272)
      {
       click(8);
       if(flag)
	  break;//GOES TO MAIN
      }
   if(((x1>470&&x1<570)&&y1>252)&&y1<272)
      click(9);
  }
 }



void main()
 {
  initialise();
  while(1)
  {
   menu();
            coordinates();
   flag=0;
  }
 }

