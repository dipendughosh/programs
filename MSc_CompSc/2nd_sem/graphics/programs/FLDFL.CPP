#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>


class algo
{
	private:
		int xMax,yMax;
	public:
		algo()
		{
		}
		void screenInitialize();
		void drawobject();
		void fill(int,int,int,int);
		~algo()
		{
			closegraph();
		}
};

void algo::screenInitialize()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");
	outport(0x0378,0x00);
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		cout<<"Graphics error: %s\n"<<grapherrormsg(errorcode);
		cout<<"Press any key to halt:";
		getch();
		exit(0);
	}
	xMax=getmaxx();
	yMax=getmaxy();

}

void algo::drawobject()
{
	line(100,167,167,200);
	line(100,167,50,270);
	line(50,270,150,250);
	line(150,250,167,200);
	//boundary=getpixel(100,167);
	//putpixel(150,200,27);
	//cout<<getpixel(150,200);
	//cout<<boundary;
	//putpixel(150,200,27);
}

void algo::fill(int x, int y, int fil,int oldColor)
{
	int current = getpixel(x,y);
	FILE *ft;
	ft=fopen("e:\\testff.txt","a");
	if(ft==NULL)
	{	//printf("Destination file cannot be read");
	}
	fprintf(ft,"%d %d\n",x,y);
	fclose(ft);
	//cout<<current<<" ";.
	//cout<<x<<" "<<y;
	//getch();
	delay(2);
	if(current == oldColor)
	{
		//setColor(fill);
		putpixel(x,y,fil);
		fill(x+1,y,fil,oldColor);
		fill(x-1,y,fil,oldColor);
		fill(x,y-1,fil,oldColor);
		fill(x,y+1,fil,oldColor);
	}
	else
		return;
}

int main()
{
	algo ob;
	ob.screenInitialize();
	ob.drawobject();
	ob.fill(150,200,11,0);
	getch();
	return 0;
}