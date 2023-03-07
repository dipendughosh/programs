//PROGRAM FOR RESOLUTION OF BMP FILE

#include<stdio.h>

struct bmpfile
{
     char       bm1;
     char	bm2;
     long int   filesz;

     int        creat1;
     int	creat2;

     long int   offset;
     long int	header_sz,
		width,
		hight;

     int        clo_plane,
		bitspp;

     long int   comp_width,
		bmp_bytesz,
		hres,
		vres,
		ncol_palette,
		mean_col;
}sanjoy1;

void main()
{
      FILE *fptrr,*fptrw;
      char *oneb;
      long int i=1;
      fptrw=fopen("jhilik.bmp","rb");
      fptrr=fopen("result.bmp","wb");
      if(fptrw==NULL||fptrr==NULL)
	   printf("this file does not exist");
      else
      {
	   printf("you are succesfull");    // for programmer only
	   fread(&sanjoy1,sizeof(sanjoy1),1,fptrr);
	  fwrite(&sanjoy1,sizeof(sanjoy1),1,fptrw);
					// fseek(fptrr,-54L,1);
	   while(i++<=(sanjoy1.width*sanjoy1.hight*3))   // +54
	   {

		  fread(oneb,1,1,fptrr);
		  *oneb+=50,
		  fwrite(oneb,1,1,fptrw);

	    }
		fclose(fptrr);
		fclose(fptrw);
      }
     
 }

