//PROGRAM FOR RESOLUTION OF BMP FILE

#include<stdio.h>

struct bmpfile
{
     
     char       bm[2];
     int        filesz;
     short int  creat1;
     short int	creat2;
     int        offset;
     int header_sz;
     int width;
     int hight;
     short int  clo_plane;
     short int bitspp;
     int        comp_width;
     int bmp_bytesz;
     int hres;
     int vres;
     int ncol_palette;
     int mean_col;
}obj;

int main()
{
      FILE *fptrr,*fptrw;
      char *oneb;
      long int i=1;
   
      fptrw=fopen("my.bmp","rb");
      fptrr=fopen("result.bmp","wb");
      
      if(fptrw==NULL||fptrr==NULL)
	   printf("this file does not exist");
      else
      {
	   printf("you are succesfull");    
	    printf("\n%d\n",sizeof(obj));
	   // for programmer only
	   fread(&obj,sizeof(obj),sizeof(obj),fptrr);
	   fwrite(&obj,sizeof(obj),sizeof(obj),fptrw);
	    printf("%d,%d,%d",obj.width,obj.hight,sizeof(obj));// fseek(fptrr,-54L,1);
	   while(i++<=(obj.width*obj.hight*3))   // +54
	   {

		  fread(oneb,1,1,fptrr);
		  //*oneb+=50,
		  fwrite(oneb,1,1,fptrw);

	    }
		fclose(fptrr);
		fclose(fptrw);
      }
     
 }

