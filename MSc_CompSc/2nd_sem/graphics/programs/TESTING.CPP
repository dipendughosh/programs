#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//";INCLUDE GETPIXEL.CEX"

union REGS i,o;

int main()
{	//clrscr();
	int driver,mode,x,y,but;
	driver=DETECT;
	initgraph(&driver,&mode,"C:\\tc\\bgi");
	outport(0x0378,0x00);
	gotoxy(14,11);
	cout<<".";
	outtextxy(85,300,".");
	putpixel(89,320,1);
	/*setcolor(LIGHTRED);
	rectangle(30,30,635,460);
	rectangle(70,155,160,180);
	setfillstyle(SOLID_FILL,YELLOW);
	rectangle(180,130,320,170);
	floodfill(202,132,LIGHTRED);
	rectangle(180,240,320,280);
	floodfill(202,242,LIGHTRED);
	rectangle(350,130,498,170);
	floodfill(352,132,LIGHTRED);
	rectangle(350,240,490,280);
	floodfill(352,242,LIGHTRED);
	line(250,220,420,220);
	line(335,220,335,210);
	line(250,220,250,240);
	line(420,220,420,240); */
	/*outtextxy(188,45,"-:D C M O T O R:-");
	outtextxy(195,75,"-:Control Panal:-");
	outtextxy(85,300,"Instructions:-");
	outtextxy(210,140,"Clockwise:-");
	outtextxy(360,140,"Anticlockwise:-");
	outtextxy(210,250,"Increase:-");
	outtextxy(380,250,"Decrease:-");
	setcolor(10);
	outtextxy(310,185,"Speed");
	outtextxy(60,130,"Speed Factor");
	setcolor(YELLOW);*/
	getch();
	return 0;
}























