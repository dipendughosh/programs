#include<stdio.h>
struct bmpfile
{

char       bm1,
		bm2;

     long int   filesz;

     int        creat1;
     int	creat2;

     long int   offset,
		header_sz,
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
}jhilik;

main()
{
	FILE *fp,*fptr;
	char *ch;
	int i,j,k;
	fp=fopen("jhilik.bmp","rb");
	fptr=fopen("result.bmp","wb");
	fread(&jhilik,sizeof(jhilik),1,fp);
	fwrite(&jhilik,sizeof(jhilik),1,fptr);
	for(i=0;i<jhilik.hight;i++)
	{
		for(j=0;j<jhilik.width;j++)
		{
			for(k=0;k<3;k++)
			{
				fread(ch,1,1,fp);
				fwrite(ch,1,1,fptr);
			}
		}
	}

                        	fclose(fp);
				fclose(fptr);

	
}
