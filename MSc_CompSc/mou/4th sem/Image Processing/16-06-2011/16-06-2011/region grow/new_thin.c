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
    
     int hight;
     fread(&hight,4,1,fptr);
     fwrite(&hight,4,1,fptw);
    
     int width;
     fread(&width,4,1,fptr);
     fwrite(&width,4,1,fptw);
    
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
int width,hight;

int data1[800][800],data2[800][800];

main(int argc, char *argv[])
{

 
// Initialization

int i,j,k,change;
unsigned char oneb;


fptr=fopen(argv[1],"rb");//Source File
fptw=fopen(argv[2],"wb");//Destination File

// Reading & writing The Header
readheader(&width,&hight);


//writing into array
      for(i=0;i<width;i++)
      {
	for(j=0;j<hight;j++)
	{
		fread(&oneb,1,1,fptr);
		fread(&oneb,1,1,fptr);
		fread(&oneb,1,1,fptr);
		if(oneb==0)
		{
			data1[i][j]=0;
		}
		else
		{
			data1[i][j]=255;
			
		}
	}
	
      }

      
// Performing Morphological Operations
do
{

change=0;
for(k=1;k<=8;k++)
{              
  for(i=0;i<width;i++)
  {
    for(j=0;j<hight;j++)
    { 
	 
      if(i==0||i==width-1||j==0||j==hight-1)
              data2[i][j]=data1[i][j];
      else
      {                
         
             switch(k)
	     {
		case 1: if(data1[i][j]==0&&data1[i+1][j-1]==0&&data1[i+1][j]==0&&data1[i+1][j+1]==0&&data1[i-1][j-1]==255&&data1[i-1][j]==255&&data1[i-1][j+1]==255)
			{
			   data2[i][j]=255;
			   change++;
			}
			else
			   data2[i][j]=data1[i][j];
			break;
		case 2: if(data1[i][j]==0&&data1[i][j-1]==0&&data1[2][j]==0&&data1[i+1][j-1]==0&&data1[i-1][j]==255&&data1[i-1][j+1]==255&&data1[i][j+1]==255)
			{
			   data2[i][j]=255;
			   change++;
			}
			else
			   data2[i][j]=data1[i][j];
			break;
		case 3: if(data1[i][j]==0&&data1[i-1][j-1]==0&&data1[i][j-1]==0&&data1[i+1][j-1]==0&&data1[i-1][j+1]==255&&data1[i][j+1]==255&&data1[i+1][j+1]==255)
			{
			   data2[i][j]=255;
			   change++;
			}
			else
			   data2[i][j]=data1[i][j];
			break;
		case 4: if(data1[i][j]==0&&data1[i][j-1]==0&&data1[i-1][j]==0&&data1[i-1][j-1]==0&&data1[i][j+1]==255&&data1[i+1][j]==255&&data1[i+1][j+1]==255)
			{
			   data2[i][j]=255;
			   change++;
			}
			else
			   data2[i][j]=data1[i][j];
			break;

		case 5: if(data1[i][j]==0&&data1[i-1][j-1]==0&&data1[i-1][j]==0&&data1[i-1][j+1]==0&&data1[i+1][j-1]==255&&data1[i+1][j]==255&&data1[i+1][j+1]==255)
			{
			   data2[i][j]=255;
			   change++;
			}    
			else
			   data2[i][j]=data1[i][j];

			break;
		case 6: if(data1[i][j]==0&&data1[i][j+1]==0&&data1[i-1][j]==0&&data1[i-1][j+1]==0&&data1[i][j-1]==255&&data1[i+1][j-1]==255&&data1[i+1][j]==255)
			{
			   data2[i][j]=255;
			   change++;
			}
			else
			   data2[i][j]=data1[i][j];
			break;
		case 7: if(data1[i][j]==0&&data1[i-1][j+1]==0&&data1[i][j+1]==0&&data1[i+1][j+1]==0&&data1[i-1][j-1]==255&&data1[i][j-1]==255&&data1[i+1][j-1]==255)
			{
			   data2[i][j]=255;
			   change++;
			}
			else
			   data2[i][j]=data1[i][j];
			break;

		case 8: if(data1[i][j]==0&&data1[i+1][j]==0&&data1[i][j+1]==0&&data1[i+1][j+1]==0&&data1[i-1][j-1]==255&&data1[i-1][j]==255&&data1[i][j-1]==255)
			{
			   data2[i][j]=255;
			   change++;
			}
			else
			   data2[i][j]=data1[i][j];
			break;

	     }
	  }
       }
     }
//copy data2[][] into data1[]
for(i=0;i<width;i++)
  for(j=0;j<hight;j++)
    data1[i][j]=data2[i][j];

}


printf("Change=%d",change);

}while(change!=0);

// Writing The Data
		
for(i=0;i<width;i++)
      {
	for(j=0;j<hight;j++)
	{
		oneb=data2[i][j];
		fwrite(&oneb,1,1,fptw);
		fwrite(&oneb,1,1,fptw);
		fwrite(&oneb,1,1,fptw);
                  
	}
      }
      fclose(fptw);

}
