#include<stdio.h>
FILE *fptr1,*fptr2,*fptw;
main()
{
      char oneb,ch1,ch2;
      long int i,j,k;
      int width,hight;
      long int avg=0,thresh;
      //char data[1000][1000][3];
      //char output[1000][1000];
      

      fptr1=fopen("crater16.bmp","rb");
      fptw=fopen("xyz.bmp","wb");
      fptr2=fopen("moon4.bmp","rb");
        readheader2();
      printf("\nHere");
      if(fptr1==NULL||fptw==NULL)
           printf("this file does not exist");
      else
      {
           readheader1(&width,&hight);
      char data1[width][hight][3];
     char data2[width][hight][3];
      printf("Main %d,%d\n",width,hight);
           for(i=0;i<width;i++)
                {
                for(j=0;j<hight;j++)
                  {
                        fread(&oneb,1,1,fptr1);
                        data1[i][j][0]=oneb;
                        fread(&oneb,1,1,fptr1);
                        data1[i][j][1]=oneb;
                        fread(&oneb,1,1,fptr1);
                        data1[i][j][2]=oneb;
                   }
                 }
        
        for(i=0;i<width;i++)
                {
                for(j=0;j<hight;j++)
                  {
                        fread(&oneb,1,1,fptr2);
                        data2[i][j][0]=oneb;
                        fread(&oneb,1,1,fptr2);
                        data2[i][j][1]=oneb;
                        fread(&oneb,1,1,fptr2);
                        data2[i][j][2]=oneb;
                   }
                 }
        for(i=0;i<width;i++)
          {
                for(j=0;j<hight;j++)
                  {
                        if(data2[i][j][0]==0)
                        {
                                //ch1=data1[i][j][0];
                                ch1=84;
                                fwrite(&ch1,1,1,fptw);
                                //ch1=data1[i][j][1];
                                ch1=200;
                                fwrite(&ch1,1,1,fptw);
                                //ch1=data1[i][j][2];
                                ch1=250;
                                fwrite(&ch1,1,1,fptw);
                                
                                  
                          }
                        else
                        {
                                ch2=data1[i][j][0];
                                fwrite(&ch2,1,1,fptw);
                                ch2=data1[i][j][1];
                                fwrite(&ch2,1,1,fptw);
                                ch2=data1[i][j][2];
                                fwrite(&ch2,1,1,fptw);
                        }
                   }
         }
}
fclose(fptr1);
fclose(fptw);
}
                                
readheader1(int *w,int *h)
{
     char     bm[2];
     fread(bm,2,1,fptr1);
     fwrite(bm,2,1,fptw);

     int        filesz;
     fread(&filesz,4,1,fptr1);
     fwrite(&filesz,4,1,fptw);
     
     short int  creat1;
     fread(&creat1,2,1,fptr1);
     fwrite(&creat1,2,1,fptw);
    
     short int  creat2;
     fread(&creat2,2,1,fptr1);
     fwrite(&creat2,2,1,fptw);
    
     int        offset;
     fread(&offset,4,1,fptr1);
     fwrite(&offset,4,1,fptw);
    
     int header_sz;
     fread(&header_sz,4,1,fptr1);
     fwrite(&header_sz,4,1,fptw);
    
     int width;
     fread(&width,4,1,fptr1);
     fwrite(&width,4,1,fptw);
    
     int hight;
     fread(&hight,4,1,fptr1);
     fwrite(&hight,4,1,fptw);
    
     short int  clo_plane;
     fread(&clo_plane,2,1,fptr1);
     fwrite(&clo_plane,2,1,fptw);
    
     short int bitspp;
     fread(&bitspp,2,1,fptr1);
     fwrite(&bitspp,2,1,fptw);
    
     int        comp_width;
     fread(&comp_width,4,1,fptr1);
     fwrite(&comp_width,4,1,fptw);
    
     int bmp_bytesz;
     fread(&bmp_bytesz,4,1,fptr1);
     fwrite(&bmp_bytesz,4,1,fptw);
    
     int hres;
     fread(&hres,4,1,fptr1);
     fwrite(&hres,4,1,fptw);
    
     int vres;
     fread(&vres,4,1,fptr1);
     fwrite(&vres,4,1,fptw);
    
     int ncol_palette;
     fread(&ncol_palette,4,1,fptr1);
     fwrite(&ncol_palette,4,1,fptw);
    
     int mean_col;
     fread(&mean_col,4,1,fptr1);
     fwrite(&mean_col,4,1,fptw);
    
     *w=width;
     *h=hight;
      printf("%d,%d\n",width,hight);
}

readheader2()
{
     char bm[2];
     fread(bm,2,1,fptr2);
     
     int filesz;
     fread(&filesz,4,1,fptr2);
          
     short int creat1;
     fread(&creat1,2,1,fptr2);
         
     short int creat2;
     fread(&creat2,2,1,fptr2);
         
     int offset;
     fread(&offset,4,1,fptr2);
         
     int header_sz;
     fread(&header_sz,4,1,fptr2);
        
     int hight;
     fread(&hight,4,1,fptr2);
         
     int width;
     fread(&width,4,1,fptr2);
         
     short int  clo_plane;
     fread(&clo_plane,2,1,fptr2);
         
     short int bitspp;
     fread(&bitspp,2,1,fptr2);
         
     int comp_width;
     fread(&comp_width,4,1,fptr2);
         
     int bmp_bytesz;
     fread(&bmp_bytesz,4,1,fptr2);
         
     int hres;
     fread(&hres,4,1,fptr2);
         
     int vres;
     fread(&vres,4,1,fptr2);
         
     int ncol_palette;
     fread(&ncol_palette,4,1,fptr2);
     
     int mean_col;
     fread(&mean_col,4,1,fptr2);
         
}
