/*	Program to open & view a .bmp file. Convert it to 256 level grayscale & 
 *	 perform Histogram Equalization, if required.
 */

#include<stdio.h>
#include<dos.h>
#include<conio.h>	// for getch()
#include<string.h>	// for strcat()

#define MAX_COL 256

typedef unsigned char unch;
char far *screen = (char far *) 0xA0000000; // Actual Screen Buffer Address
unch pal_buf[MAX_COL][3]; // array to save palette data read from file
int xmax, ymax; // max resolution of screen. Value set by set_graphics_mode()

struct bmpHeader 
{
	char b,m;		// should be 'B' & 'M'
	long filesize;  // size of file in bytes
	long zero;		// always 0
	long dataoffset;// offset of Data
	long remsize;	// remaining size of the header
	long cols, rows;// width & height of image
	int planes;		// no. of color planes in the image (for us always 1)
	int bitsperpix; // no. of bits to represent a pixel (for us always 8)
	long compression, cmpSize; 	// specifies compressed image
	long xscale, yscale;        // Image Scaled ?
	long colors, impColors;
}head;

void set_graphics_mode() 
{
	union REGS i;
	i.h.ah = 0x0;	// function 0h; set video mode
	i.h.al = 0x13;	// video mode; 13h = G320x200x256
	int86(0x10, &i,&i); // call interrupt 10h
	xmax = 320;
	ymax = 200;
}

void set_text_mode() 
{
	union REGS i;
	i.h.ah = 0x0;	// function 0h; set video mode
	i.h.al = 0x3;	// video mode; 3h = T80x25x16
	int86(0x10,&i,&i); // call interrupt 10h
	xmax = 0;
	ymax = 0;
}

void set_palette (int color, unch red, unch green, unch blue) 
{
	outportb(0x3C8,color);	// write index no. to graphic card port 0x3c8 (Palette Index No.)
	outportb(0x3C9,red);	// write vals of Red, Green & Blue (Palette Color)
	outportb(0x3C9,green);
	outportb(0x3C9,blue);
}

void show_pixel(int x, int y, unch color) // show 'color' pixel at (x,y)
{ 
	if(y>=0 && y<ymax) 		// show only if falls within screen
		if(x>=0 && x<xmax)
			screen[y*xmax+x] = color;
}

int get_gray(unch index) // return graylevel corresponding to palette no 'index'
{ 
	unch r, g, b;
	int gray;
	r = pal_buf[(int)index][0];
	g = pal_buf[(int)index][1];
	b = pal_buf[(int)index][2];
	gray = (int)(0.299*r + 0.587*g + 0.114*b);
	gray = gray<<2;
	return gray;
}

void set_hw_palette() 		// set h/w palette from saved palette buffer
{
	int index;
	for(index=0;index<MAX_COL;index++)  // read saved palette data from buffer & change hardware palette
		set_palette(index, pal_buf[index][0], pal_buf[index][1], pal_buf[index][2]);	// store the info in system palette
}

void show_histogram(FILE *file,int width,int height) 
{
	float hist_data[MAX_COL]; // to keep histogram data
	unsigned long ctr;
	int x,y;
	float max = 0;
	void clear_screen();

	for(ctr=0;ctr<MAX_COL;ctr++)
		hist_data[ctr]=0;	// initialize all cells with zeroes

	fseek(file,54+MAX_COL*4,SEEK_SET);
	ctr=0;
	while(ctr<(unsigned long)width*height) 
	{
			hist_data[get_gray(fgetc(file))]++;	// inc cell, corresponding to file color-index-no, in 'histo' by 1
			ctr++;					// increment counter
	}
	for(x=0;x<MAX_COL;x++) // find max no of pixels of the same color
		if(hist_data[x]>max)
			max=hist_data[x];

	clear_screen();
	set_palette(0,0,0,0);		// background = BLACK
	set_palette(1,62,62,62);	// foregroung = WHITE
	/* create axes */
	for(x=0; x<=MAX_COL;x++)
		show_pixel(20+x,ymax-2,1); // x-axis
	for(y=0; y<ymax-2;y++)
		show_pixel(20,y,1); // y-axis

	max /= ymax-5; // to keep max y scale within screen (1702200221157)
	for(x=0;x<MAX_COL;x++)
		for(y=0;y<=(int)hist_data[x]/max;y++)
			show_pixel(22+x,ymax-2-y,1);
	getch();
	flushall();
	set_palette(0,pal_buf[0][0],pal_buf[0][1],pal_buf[0][2]); // reset palette index 0 to original color
	set_palette(1,pal_buf[1][0],pal_buf[1][1],pal_buf[1][2]); // reset palette index 1 to original color
}

void equalize_histogram(FILE *file,int width,int height) 
{
	unsigned long ctr=0;
	float eq_data[MAX_COL];	// keep probability data

	for(ctr=0;ctr<MAX_COL;ctr++)
		eq_data[ctr]=0;	// initialize all cells with zeroes

	fseek(file,54+MAX_COL*4,SEEK_SET);	
	ctr=0;
	while(ctr<(unsigned long)width*height) 
	{
			eq_data[get_gray(fgetc(file))]++;	// inc cell, corresponding to file color-index-no, in 'eq_data' by 1
			ctr++;					// increment counter
	}
	for(ctr=0;ctr<MAX_COL;ctr++)	
		eq_data[ctr] /= (float)width; 	// p.d.f. (part I) (Probability Density Function)
	for(ctr=0;ctr<MAX_COL;ctr++)
		eq_data[ctr] /= (float)height; 	// p.d.f. (part II)
	for(ctr=0;ctr<MAX_COL;ctr++)
		eq_data[ctr] *= 255;			// complete Transformation function
	for(ctr=1;ctr<MAX_COL;ctr++)	
		eq_data[ctr] += eq_data[ctr-1]; // c.d.f. (Cummulative Density Function)
	for(ctr=0;ctr<MAX_COL;ctr++)
		pal_buf[ctr][0]=pal_buf[ctr][1]=pal_buf[ctr][2]=(unch)eq_data[ctr]>>2; // set palette_buffer to return new colors for old graylevel nos.
	set_hw_palette();		// resave h/w palette, since palette data changed
}

void clear_screen() 
{
	int x, y;
	for(y=0;y<=ymax;y++)  // clear screen using background color
		for(x=0;x<=xmax;x++)
			show_pixel(x,y,0);
}

void show_image_on_screen(FILE *file,int width,int height,int down_scalex,int down_scaley) 
{
	int x,y;
	fseek(file,54+MAX_COL*4,SEEK_SET); // start from the first pixel data
	for(y=height/down_scaley; y>=0; y--)  // coz image saved in file upside down
	{
		for(x=0; x<width/down_scalex; x++)  // (width/down_scalex) coz this may be smaller than screen width (with excessive down_sizin)
		{
			show_pixel(x, y, fgetc(file));	// read from file & show at (x,y) of screen
			fseek(file,down_scalex-1,SEEK_CUR); // move to the next data to be read from file (down_scalex bytes down the line)
		}
		fseek(file,width%down_scalex,SEEK_CUR); // to correct output pattern error when 'width' not completely divisible by 'down_scalex'
		fseek(file,(down_scaley-1)*width,SEEK_CUR); // (down_scaley-1) coz, if down_scaley==1, then goto next pixel & not jump over the next line
	}
}

void show_bmp(char *name)  // show bmp file on screen
{
	FILE *file;			// pointer to file to be opened
	unch r, g, b;		// rgb values (type unsigned char)
	int x, y;			// screen coords
	int width, height;	// image width & Height
	int index, flag=1;			// index of color palette; flag=1/0:enable/disable histogram
	int down_scalex, down_scaley;	// scale factor for showing larger images within screen
	float gray;			// to store gray level;
	char c, aspect;

	file = fopen(name, "rb"); // open file for reading in binary mode
	if(file == NULL)
	{
		printf("File Not Found !!!! \n\nClosing...."); 
		getch();
		return; // file doesn't exist
	}

	fread(&head, sizeof(head),1, file);	//read header from file
	if(head.b!='B' || head.m!='M' || head.bitsperpix!=8 || head.compression!=0 || head.planes!=1) 
	{
		fclose(file); 
		printf("Gadbad !!! Exiting....."); 
		getch();
		return;
	}

	printf("\n\nColor or Grayscale (c/g) :");
	scanf("%c",&c); 
	flushall();

	printf("\nPreserve Aspect Ratio of original image on screen (y/n): ");
	scanf("%c",&aspect); flushall();

	fseek(file, 54, SEEK_SET);	// start reading palette (always present for 256 col (8 bitsperpix) images)
	/* save palette in buffer */
	for(index=0;index<MAX_COL;index++)  // read palette from file; 4 bytes/color; blue, green, red, reserved
	{
		b = fgetc(file); b=b>>2;	// colors stored as bgr in file
		g = fgetc(file); g=g>>2;
		r = fgetc(file); r=r>>2;
		if(c=='g') 	// grayscale chosen
		{
			gray = 0.299*r + 0.587*g + 0.114*b; // gray value = luminance
			r = (int)gray;	g = b = r;	// all color values same (grayscale)
		}
		pal_buf[index][0]=r;		pal_buf[index][1]=g;		pal_buf[index][2]=b;
		fgetc(file);			// for the fourth reserved faltu byte
	}
	/* Set width & height & Downsize factors */
	width = head.cols;	// read image width from header
	height = head.rows; // image height
	while(width%4 != 0)
		width++; // make width a multiple of 4

	set_graphics_mode(); // change to graphics mode
	/* calculate scale factors */
	down_scalex = width / xmax;
	down_scaley = height / ymax;

	if(down_scalex<=1)
		down_scalex=1; // for images smaller-
	if(down_scaley<=1)	
		down_scaley=1; //	-than screen
	if(down_scaley*ymax<height)
		down_scaley++; // increase factor if image to be show on screen larger than screen itself

	if(aspect=='y') 
	{
		if(down_scalex>=down_scaley)	
			down_scaley=down_scalex; // to preserve aspect ratio of image on screen
		else	
			down_scalex=down_scaley;
	}
	set_hw_palette();	// set h/w palette from saved palette buffer
	c = 0;
	while(down_scalex>0 && down_scaley>0) 
	{
		clear_screen();
		show_image_on_screen(file,width,height,down_scalex,down_scaley); // show image on screen with given scale factors
		if(c=='h' && flag==0)
		{  // show histogram of equalized image AFTER showing the image
			c=getch();	
			flushall();
			show_histogram(file,width,height);
			flag=-1;
		}
		else 
		{
			c=getch(); 
			flushall();
		}
		if(c=='+')
 		{	
			down_scalex--;
			down_scaley--;
		}
		else if(c=='-')
		{	
			down_scalex++;
			down_scaley++;	
		}
		else if(c=='h' && flag==1)  // perform Histogram Equalization if 'h' pressed & equalization not already done
		{
			show_histogram(file,width,height);
			equalize_histogram(file, width, height); flag=0;
		}
		else if((int)c==27)	
			break; // close if <esc> pressed
	}
	fclose(file);
	set_text_mode();	// return to text mode
	return;
}

void main()
 {
	char name[100];
	int i;
	clrscr();
	printf("\n\nEnter Filename (256 color bmp image) : ");
	scanf("%s",&name); 
	flushall();
	/* Append .bmp if its not added by the user */
	for(i=0;name[i]!='.' && name[i]!='\0';i++);
	if(name[i]!='.')	
		strcat(name,".bmp");
	show_bmp(name); 	// give the file name with correct path. Also, for each back-slash add another, ie, c:\\windows\\xxxxx
}