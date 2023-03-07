//Converting to negative image
#include<stdio.h>

FILE *fptr,*fptw;

readheader(int *w,int *h)
{
     char bm[2];
     int filesz;
     short int creat1;
     short int creat2;
     int offset;
     int header_sz;
     int width;
     int hight;
     short int clo_plane;
     short int bitspp;
     int comp_width;
     int bmp_bytesz;
     int hres;
     int vres;
     int ncol_palette;
     int mean_col;
      
     fread(bm,2,1,fptr);
     fwrite(bm,2,1,fptw);
     
     fread(&filesz,4,1,fptr);
     fwrite(&filesz,4,1,fptw);
    
     fread(&creat1,2,1,fptr);
     fwrite(&creat1,2,1,fptw);
    
     fread(&creat2,2,1,fptr);
     fwrite(&creat2,2,1,fptw);
     
     fread(&offset,4,1,fptr);
     fwrite(&offset,4,1,fptw);
     
     fread(&header_sz,4,1,fptr);
     fwrite(&header_sz,4,1,fptw);
     
     fread(&width,4,1,fptr);
     fwrite(&width,4,1,fptw);
    
     fread(&hight,4,1,fptr);
     fwrite(&hight,4,1,fptw);
    
     fread(&clo_plane,2,1,fptr);
     fwrite(&clo_plane,2,1,fptw);
     
     fread(&bitspp,2,1,fptr);
     fwrite(&bitspp,2,1,fptw);
    
     fread(&comp_width,4,1,fptr);
     fwrite(&comp_width,4,1,fptw);
    
     fread(&bmp_bytesz,4,1,fptr);
     fwrite(&bmp_bytesz,4,1,fptw);
    
     fread(&hres,4,1,fptr);
     fwrite(&hres,4,1,fptw);
    
     fread(&vres,4,1,fptr);
     fwrite(&vres,4,1,fptw);
    
     fread(&ncol_palette,4,1,fptr);
     fwrite(&ncol_palette,4,1,fptw);
    
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

      fptr=fopen("my.bmp","rb");
      fptw=fopen("copymy.bmp","wb");

      if(fptr==NULL||fptw==NULL)
	   printf("this file does not exist");
      else
      {
	   readheader(&width,&hight);
           printf("%d,%d\n",width,hight);
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

                                                                  
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
