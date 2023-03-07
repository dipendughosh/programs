#include<stdio.h>
FILE *fptr,*fptw;

readheader(int *w,int *h)
{
     char bm[2];
     fread(bm,2,1,fptr);
     fwrite(bm,2,1,fptw);

     int filesz;
     fread(&filesz,4,1,fptr);
     fwrite(&filesz,4,1,fptw);
     
     short int creat1;
     fread(&creat1,2,1,fptr);
     fwrite(&creat1,2,1,fptw);
    
     short int creat2;
     fread(&creat2,2,1,fptr);
     fwrite(&creat2,2,1,fptw);
    
     int offset;
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
    
     int comp_width;
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
    
     int ncol_palette;
     fread(&ncol_palette,4,1,fptr);
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
      char oneb,ch1,ch2;
      long int i,j,k;
      int width,hight,hupr,hlow,hdiff,vl,vr,vdiff;
      long int avg=0,thresh;
      
      int gupr,glow,m,n;
      //long int data[width][hight][3];
      //int output[width][hight];

      fptr=fopen("rose.bmp","rb");
      fptw=fopen("copyrose.bmp","wb");

      if(fptr==NULL||fptw==NULL)
	   printf("this file does not exist");
      else
      {
	   readheader(&width,&hight);
	   char data[width][hight][3];
	   char output[width][hight];
	   for(i=0;i<width;i++)
	   {
		for(j=0;j<hight;j++)
		{
			fread(&oneb,1,1,fptr);
			data[i][j][0]=oneb;
			fread(&oneb,1,1,fptr);
			data[i][j][1]=oneb;
			fread(&oneb,1,1,fptr);
			data[i][j][2]=oneb;
		}
	   }
	   thresh=0;
	   for(i=0;i<width;i++)
	   {
		for(j=0;j<hight;j++)
		{
			for(k=0;k<3;k++)
			{
				thresh=thresh+data[i][j][k];
		  	}
		}
           }
	   thresh=thresh/(width*hight);
	   for(i=0;i<width;i++)
	   {
  		for(j=0;j<hight;j++)
		{
			for(k=0;k<3;k++)
			{
				avg=avg+data[i][j][k];
			}
		        avg=avg/3;
			if(avg<thresh)
			{
				output[i][j]=0;
			}
			else
			{
				output[i][j]=1;
			}
		}
	   }
	   for(i=0;i<width;i++)
	   {
		for(j=0;j<hight;j++)
		{
			if(output[i][j]==0)
			{
				ch1=0;
				fwrite(&ch1,1,1,fptw);
				fwrite(&ch1,1,1,fptw);
				fwrite(&ch1,1,1,fptw);
			}
			else
			{
				ch2=255;
				fwrite(&ch2,1,1,fptw);
				fwrite(&ch2,1,1,fptw);
				fwrite(&ch2,1,1,fptw);
			}
		}
	   }
      }
      fclose(fptr);
      fclose(fptw);

      char a[width][hight];
      char a1[width][hight];
      fptr=fopen("copyrose.bmp","rb");
      fptw=fopen("copyrose1.bmp","wb");	
      readheader(&width,&hight);
      //writing into array
      for(i=0;i<width;i++)
      {
	for(j=0;j<hight;j++)
	{
		fread(&oneb,1,1,fptr);
		fread(&oneb,1,1,fptr);
		fread(&oneb,1,1,fptr);
		/*if(oneb==0)
		{
			a[i][j]=0;
			a1[i][j]=0;
		}
		else
		{
			a[i][j]=255;
			a1[i][j]=255;
		}*/
		a[i][j]=oneb;
		a1[i][j]=oneb;
	}
	
      }

      fclose(fptr);
      //for edge detection
      for(i=1;i<width-1;i++)
      {
	for(j=1;j<hight-1;j++)
	{
		hupr=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1];
		hlow=a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
		hdiff=hupr-hlow;
		/*vl=a[i-1][j-1]+a[i][j-1]+a[i+1][j-1];
		vr=a[i-1][j+1]+a[i][j+1]+a[i+1][j+1];
		vdiff=vl-vr;
		m=hdiff+vdiff;*/
		a1[i][j]=hdiff;
	}
      }

      //making image file
      
      //printf("%d,%d",width,hight);
     // while(n<=(width*hight*3))   
      for(i=0;i<width;i++)
      {
	for(j=0;j<hight;j++)
	{
		oneb=a1[i][j];
		fwrite(&oneb,sizeof(char),1,fptw);
		fwrite(&oneb,sizeof(char),1,fptw);
		fwrite(&oneb,sizeof(char),1,fptw);
                  
	}
      }
      fclose(fptw);

}




