
// Initialization
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
int row,col;

void region(int,int);

static int data[800][800],grow[800][800],result[800][800],temp[800][800];
int l=256,count=0,lfinal=0,p=0,q=0,r=0,flag=0;

int i,j,k,count1;



main(int argc, char *argv[])
{

 
// Initialization


unsigned char oneb;


fptr=fopen(argv[1],"rb");//Source File
fptw=fopen(argv[2],"wb");//Destination File

// Reading & writing The Header
readheader(&row,&col);


//writing into array
      for(i=0;i<row;i++)
      {
	for(j=0;j<col;j++)
	{
		fread(&oneb,1,1,fptr);
		fread(&oneb,1,1,fptr);
		fread(&oneb,1,1,fptr);
		if(oneb==0)
		{
			data[i][j]=0;
		}
		else
		{
			data[i][j]=255;
			
		}
	}
	
      }

      
            
   for(i=0;i<row;i++)
         for(j=0;j<col;j++)
    {    if((i==0)||(i==row-1)||(j==0)||(j==col-1))
           data[i][j]=0;
                     
       
    }

           
       

   for(i=0;i<row;i++)
         for(j=0;j<col;j++)
    {    grow[i][j]=data[i][j];    /*    MAKING A COPY OF THE IMAGE     */
       
    }



for(i=0;i<row;i++)
         for(j=0;j<col;j++)
    {  
          result[i][j]=255;        /*  ASSIGING THE RESULT IMAGE TOTALLY WHITE   */
          
      
 
    }





     for(i=1;i<row-1;i++)
         for(j=1;j<col-1;j++)
           {
                      
                      if(grow[i][j]==255)
                                      
                   {     
                          printf("%d \n",l);   /*  REGION GROW RECURSIVE FUNCTION   */
                           grow[i][j]=l;
                         region(i,j);
                            l++;
                    }
           }


      
 

while(l>255)
{

for(i=1;i<row-1;i++)
         for(j=1;j<col-1;j++)
           {
                          
                      if(grow[i][j]==l)
                       {   data[i][j]=l;
                    
                        
                       
                           if(grow[i+1][j]==0)
                              data[i+1][j]=l;
                                
                            if(grow[i][j+1]==0)        /* TAKING THE 4-NEIGHBOUR BLACK POINTS AND ASSIGNING THEM LEVEL VALUE   */
                                data[i][j+1]=l;

                             if(grow[i-1][j]==0)
                                 data[i-1][j]=l;
                              
                               if(grow[i][j-1]==0)
                                 data[i][j-1]=l;
                         
                         }   
                       
                           
                               
                     
           }
count1=0;
for(i=0;i<row;i++)
         for(j=0;j<col;j++)
 {         
             if(data[i][j]==l)
             {   count1++;
                temp[i][j]=5;
              }
              else
                 temp[i][j]=255;
              
 }




 // ASSIGNING THE LEVEL TO A TEMPORARY ARRAY AND THEN FINDING THE CONTOUR  

      
if (count1>100)
{
             for(i=0;i<row-1;i++)
                    for(j=0;j<col-1;j++)
                      { 
                               if(temp[i][j]==5)
                                { result[i][j]=0;
                                    break;
                                }                       
                       }


         for(i=0;i<row-1;i++)
                    for(j=col-1;j>0;j--)
                      { 
                               if(temp[i][j]==5)
                                { 
                                       result[i][j]=0;
                                         
                                    break;
                                }
                       }
      
                    for(j=0;j<col-1;j++)
                         for(i=0;i<row-1;i++)
                      { 
                               if(temp[i][j]==5)
                                {      result[i][j]=0;   
                                    break;
                                }

                        }
    
                    for(j=0;j<col-1;j++)
                         for(i=row-1;i>0;i--)
                      { 
                               if(temp[i][j]==5)
                                { result[i][j]=0;
                                   
                                    break;
                                }
                       }



 
} 
l--;
}

// Writing The Data
		
for(i=0;i<row;i++)
      {
	for(j=0;j<col;j++)
	{
		oneb=result[i][j];
		fwrite(&oneb,1,1,fptw);
		fwrite(&oneb,1,1,fptw);
		fwrite(&oneb,1,1,fptw);
                  
	}
      }
      fclose(fptw);


       
                     

}




    // THE REGION GROW FUNCTION TO TRAVERSE THE WHOLE BOUNDED REGION

void region(int i,int j)
{   

        
              
             // printf("\n I am in the if part %d %d %d\n",i,j,count);
                 if(i<row-1)
                 if(grow[i+1][j]==255)
               {
                       
                      grow[i+1][j]=l;
                       region(i+1,j);
                      
                }

                  if(j<col-1)
                  if(grow[i][j+1]==255)
               {
                      
                      grow[i][j+1]=l;
                       region(i,j+1);
                }
               if(i>0)
                if(grow[i-1][j]==255)
               {
                       
                      grow[i-1][j]=l;
                       region(i-1,j);
                }
               if(j>0)
                 if(grow[i][j-1]==255)
               {
                    
                      grow[i][j-1]=l;
                       region(i,j-1);
                }
                    
                   
  }       
