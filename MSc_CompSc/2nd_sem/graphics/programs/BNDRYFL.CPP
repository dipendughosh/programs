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
		//FILE *ft;
	public:
		algo()
		{
			/*ft=fopen("f:\\testbf.txt","w");
			fclose(ft);
			ft=fopen("f:\\testbf.txt","a");
			if(ft==NULL)
			{	//printf("Destination file cannot be read");
			} */
		}
		void screenInitialize();
		void drawobject();
		void fill(int,int,int);
		~algo()
		{
			//fclose(ft);
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
	yMax=getmaxy();     /*
	setbkcolor(10);
	cout<<getpixel(10,10);
	getch();              */

}

void algo::drawobject()
{
	rectangle(0,0,getmaxx(),getmaxy());
	/*line(100,167,167,200);
	line(100,167,50,270);
	line(50,270,150,250);
	line(150,250,167,200);
	boundary=getpixel(100,167);
	//putpixel(62,265,5); */
	line(200,200,300,300);
	line(200,200,100,300);
	line(100,300,150,450);
	line(300,300,150,450);
	//boundary=getpixel(200,200);
	//putpixel(250,300,27);
	//putpixel(251,301,27);
	//putpixel(108,230,27);
	//cout<<getpixel(150,200);
	//cout<<boundary;
	//putpixel(150,200,27);
}

void algo::fill(int x, int y, int fil)
{
	int current = getpixel(x,y);
	//fprintf(ft,"%d %d %d\n",x,y,current);
	//cout<<current<<" ";.
	//cout<<x<<" "<<y;
	//getch();
	delay(1);
	/*if(x==108 || y==230)
		return;
	else
	{ */
		if((current != boundary) && (current != fil))
		{
			//setcolor(fil);
			putpixel(x, y,fil);
  /*			if(x!=108  || y>=230)
			{*/
				fill(x+1,y,fil);
				fill(x-1,y,fil);
		       /*	}
			if(x<=108 || y!=230)
			{*/
				fill(x,y-1,fil);
				fill(x,y+1,fil);
				fill(x+1,y+1,fil);
				fill(x-1,y-1,fil);
				fill(x+1,y-1,fil);
				fill(x-1,y+1,fil);
		       //	}
		}
		else
			return;
       //	}
}

int main()
{
	algo ob;
	ob.screenInitialize();
	ob.drawobject();
//	ob.fill(1,1,12);
	ob.fill(250,300,11);
	getch();
	return 0;
}

