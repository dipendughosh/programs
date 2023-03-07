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
		int xMax,yMax,boundary;
		FILE *ft;
	public:
		algo()
		{
			ft=fopen("f:\\testbf.txt","w");
			fclose(ft);
			ft=fopen("f:\\testbf.txt","a");
			if(ft==NULL)
			{	;//printf("Destination file cannot be read");
			}
		}
		void screenInitialize();
		void drawobject();
		void fill(long int,long int,int);
		~algo()
		{
			fclose(ft);
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
	rectangle(0,0,getmaxx(),getmaxy());
	boundary=getpixel(0,0);
}

void algo::fill(long int x,long int y, int fil)
{
	long int current = getpixel(x,y);
	fprintf(ft,"%ld %ld %ld\n",x,y,current);
	delay(1);
	if(x==513 && y==5)
		return;
	if((current != boundary) && (current != fil))
	{
		//setcolor(fil);
		putpixel(x, y,fil);
		/*if(x!=512 || y<5 || y>5)
		{ */
			fill(x+1,y,fil);
			fill(x-1,y,fil);
		/*}
		if(x>512 || x<512 || y!=5)
		{ */
			fill(x,y-1,fil);
			fill(x,y+1,fil);
		//}
	}
	else
		return;
}

int main()
{
	algo ob;
	ob.screenInitialize();
	ob.drawobject();
	ob.fill(1,1,12);
	getch();
	return 0;
}