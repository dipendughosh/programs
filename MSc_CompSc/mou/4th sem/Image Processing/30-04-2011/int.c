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
     int hight;
     int width;
     short int  clo_plane;
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

     fread(&hight,4,1,fptr);
     fwrite(&hight,4,1,fptw);

     fread(&width,4,1,fptr);
     fwrite(&width,4,1,fptw);

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
      unsigned char oneb,ch1,ch2;
      int i,j,k;
      int width,hight;
      int x,y,avg,v1,v2,m,hupr,hlow,hdiff,vl,vr,vdiff;
      int n1=0,n2=0,t,t1;
      unsigned char data[1000][1000][3];
	   unsigned char output[1000][1000];
      unsigned char a[1000][1000];
      unsigned char a1[1000][1000];
		unsigned char a2[1000][1000];
      int l,level,c=0,constant=50;

      //int gupr,glow,m,n;
      //long int data[width][hight][3];
      //int output[width][hight];

      fptr=fopen("moon.bmp","rb");
      fptw=fopen("copymoon.bmp","wb");

      if(fptr==NULL||fptw==NULL)
	   printf("this file does not exist");
      else
      {
	   readheader(&width,&hight);

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

      fptr=fopen("copymoon.bmp","rb");
      fptw=fopen("copymoon1.bmp","wb");
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
			a[i][j]=0;
		}
		else
		{
			a[i][j]=255;

		}
	}

      }

      fclose(fptr);

      for(i=0;i<width;i++)
      	for(j=0;j<hight;j++)
              a1[i][j]=0;



      //for edge detection
      for(i=1;i<width-1;i++)
      {
	for(j=1;j<hight-1;j++)
	{
		hupr=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1];
		hlow=a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
		hdiff=hupr-hlow;
		vl=a[i-1][j-1]+a[i][j-1]+a[i+1][j-1];
		vr=a[i-1][j+1]+a[i][j+1]+a[i+1][j+1];
		vdiff=vl-vr;
		m=abs(hdiff)+abs(vdiff);
                if(m==0)
		    a1[i][j]=255;
                else
                    a1[i][j]=0;
	}
      }

      for(i=0;i<width;i++)
      {
	for(j=0;j<hight;j++)
	{
		oneb=a1[i][j];
		fwrite(&oneb,1,1,fptw);
		fwrite(&oneb,1,1,fptw);
		fwrite(&oneb,1,1,fptw);

	}
      }
      fclose(fptw);
//for region

fptr=fopen("copymoon1.bmp","rb");
fptw=fopen("intensity.bmp","wb");
readheader(&width,&hight);
for(i=0;i<width;i++)
      {
	for(j=0;j<hight;j++)
	{
		fread(&oneb,1,1,fptr);
		fread(&oneb,1,1,fptr);
		fread(&oneb,1,1,fptr);
		if(oneb==0)
		{
			a1[i][j]=0;
		}
		else
		{
			a1[i][j]=255;

		}
	}

      }
l=256;
for(i=1;i<=width;i++)
{
	for(j=1;j<=hight;j++)
	{
		a2[i][j]=255;
		output[i][j]=255;
	}
}
for(i=1;i<=width;i++)
{
	for(j=1;j<=hight;j++)
	{
		if(a1[i][j]==255)
		{
		region(a1,a2,l,i,j);
		l=l+1;
		}
	}
}
l=l-1;
for(level=256;level<=l;level++)
{
	for(i=1;i<=width;i++)
	{
		for(j=1;j<=hight;j++)
		{
			if(a2[i][j]==level)
			c=c+1;
		}
	}
			if(c>=constant)
			{
				for(i=1;i<=width;i++)
				{
					for(j=1;j<=hight;j++)
					{
						if((a2[i][j]==level)&&((a2[i+1][j]!=level)||(a2[i-1][j]!=level)||(a2[i][j+1]!=level)||(a2[i][j-1]!=level)))
						output[i][j]=0;
					}
				}
			}
}
for(i=0;i<width;i++)
      {
	for(j=0;j<hight;j++)
	{
		oneb=output[i][j];
		fwrite(&oneb,1,1,fptw);
		fwrite(&oneb,1,1,fptw);
		fwrite(&oneb,1,1,fptw);

	}
      }
}
region(unsigned char a1[1000][1000],unsigned char a2[1000][1000],int l,int x,int y)
{
	if(a1[x+1][y]!=0)
	{
		a2[x+1][y]=l;
		region(a1,a2,l,x+1,y);
	}
	if(a1[x-1][y]!=0)
	{
		a2[x-1][y]=l;
		region(a1,a2,l,x-1,y);
	}
	if(a1[x][y+1]!=0)
	{
		a2[x][y+1]=l;
		region(a1,a2,l,x,y+1);
	}
	if(a1[x][y-1]!=0)
	{
		a2[x][y-1]=l;
		region(a1,a2,l,x,y-1);
	}
}				
			

