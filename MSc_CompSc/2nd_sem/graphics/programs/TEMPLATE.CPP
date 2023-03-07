#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main()
{	//clrscr();
	int driver,mode,x,y,but;
	driver=DETECT;
	initgraph(&driver,&mode,"C:\\tc\\bgi");
	outport(0x0378,0x00);
	gotoxy(14,11);
	cout<<".";
	outtextxy(85,300,":");
	putpixel(89,320,255);
	x=getmaxx();
	y=getmaxy();
	cout<<"X = "<<x<<"\nY = "<<y;
	//closegraph();
	getch();
	closegraph();
	return 0;
}