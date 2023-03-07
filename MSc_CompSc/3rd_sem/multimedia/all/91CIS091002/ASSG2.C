#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
	int gd,gm;
	int i, x1=25, y1=0, x2=615, y2=25;
	gd=DETECT;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	setcolor(3);

	for(i=1; i<=11; i++)
	{
		setfillstyle(i, i);
		bar(x1, y1, x2, y2);
		y1+=25;
		y2+=25;
	//	getch();
	}
	setfillstyle(1, 15);
	bar(x1, y1, 315, y2+150);
while(!kbhit())
{
	putpixel(random(290)+25,random(175)+275,random(16));
	setcolor(random(16));
	circle(450,375,random(100));
}
getch();
closegraph();
}