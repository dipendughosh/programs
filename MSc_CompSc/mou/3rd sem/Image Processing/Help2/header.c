#include<stdio.h>

FILE *fptr,*fptw;
readheader(int *w,int *h)
{
     char       bm[2];
     fread(bm,2,1,fptr);
     fwrite(bm,2,1,fptw);

     int        filesz;
     fread(&filesz,4,1,fptr);
     fwrite(&filesz,4,1,fptw);
     
     short int  creat1;
     fread(&creat1,2,1,fptr);
     fwrite(&creat1,2,1,fptw);
    
     short int	creat2;
     fread(&creat2,2,1,fptr);
     fwrite(&creat2,2,1,fptw);
    
     int        offset;
     fread(&offset,4,1,fptr);
     fwrite(&offset,4,1,fptw);
    
     int header_sz;
     fread(&header_sz,4,1,fptr);
     fwrite(&header_sz,4,1,fptw);
    
     int width;
     fread(&width,4,1,fptr);
     fwrite(&width,4,1,fptw);
    
     int hight;
     fread(&hight,4,1,fptr);
     fwrite(&hight,4,1,fptw);
    
     short int  clo_plane;
     fread(&clo_plane,2,1,fptr);
     fwrite(&clo_plane,2,1,fptw);
    
     short int bitspp;
     fread(&bitspp,2,1,fptr);
     fwrite(&bitspp,2,1,fptw);
    
     int        comp_width;
     fread(&comp_width,4,1,fptr);
     fwrite(&comp_width,4,1,fptw);
    
     int bmp_bytesz;
     fread(&bmp_bytesz,4,1,fptr);
     fwrite(&bmp_bytesz,4,1,fptw);
    
     int hres;
     fread(&hres,4,1,fptr);
     fwrite(&hres,4,1,fptw);
    
     int vres;
     fread(&vres,4,1,fptr);
     fwrite(&vres,4,1,fptw);
    
     int ncol_palette;     fread(&ncol_palette,4,1,fptr);
     fwrite(&ncol_palette,4,1,fptw);
    
     int mean_col;
     fread(&mean_col,4,1,fptr);
     fwrite(&mean_col,4,1,fptw);
    
     *w=width;
     *h=hight;
      printf("%d,%d\n",width,hight);
}

main()
{
      char oneb;
      long int i=1;
      int width,hight;

      fptr=fopen("rose.bmp","rb");
      fptw=fopen("copyrose.bmp","wb");

      if(fptr==NULL||fptw==NULL)
	   printf("this file does not exist");
      else
      {
	   readheader(&width,&hight);
           printf("%d,%d",width,hight);
           while(i<=(width*hight*3))   
	   {

		  fread(&oneb,1,1,fptr);
		  oneb=255-oneb;
		  fwrite(&oneb,1,1,fptw);
                  i++;
	    }
		
      }
      fclose(fptr);
      fclose(fptw);
     
}

                                                                  
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
