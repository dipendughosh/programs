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
      unsigned char oneb,ch1,ch2;
      int i,j,k;
      int width,hight;
      int x,y,avg,v1,v2,m;
      int n1=0,n2=0,t,t1;
      
      //int gupr,glow,m,n;
      //long int data[width][hight][3];
      //int output[width][hight];

      fptr=fopen("rose.bmp","rb");
      fptw=fopen("copyrose.bmp","wb");

      if(fptr==NULL||fptw==NULL)
	   printf("this file does not exist");
      else
      {
	   readheader(&width,&hight);
	   unsigned char data[width][hight][3];
	   unsigned char output[width][hight];
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
	   t1=128;
	   do
	   {
		t=t1;
		n1=0;
		n2=0;
		v1=0;
		v2=0;
		x=0;
		y=0;
		for(i=0;i<width;i++)
	   	{
  			for(j=0;j<hight;j++)
			{
				avg=0;
				for(k=0;k<3;k++)
				{
					avg=avg+data[i][j][k];
				}
		        	avg=avg/3;
				if(avg<t)
				{
					n1=n1+1;
					v1=v1+avg;
				}
				
				else
				{
					n2=n2+1;
					v2=v2+avg;
				}
			}
		}
                if(n1!=0)
                    x=v1/n1;
		if(n2!=0)
                    y=v2/n2;	
		t1=(x+y)/2;
		m=t1-t;
		printf("\nt1=%d\tt2=%d\n",t1,t);
	   }while(abs(m)>5);
	 	
	   
	   for(i=0;i<width;i++)
	   {
  		for(j=0;j<hight;j++)
		{
			avg=0;
			for(k=0;k<3;k++)
			{
				avg=avg+data[i][j][k];
				
			}
		        avg=avg/3;
			
			if(avg<t1)
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
}
