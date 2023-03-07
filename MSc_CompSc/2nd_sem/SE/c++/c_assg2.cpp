#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char mag_no[2], ch[2], line[300], file[50];
	int width, height, maxval, ctr=0, i, p, len;
	FILE *fp1, *fp2;
	
	printf("Enter input filename: ");
	gets(file);
	len=strlen(file);
	
	fp1=fopen(file, "rb");

	file[len-4]='\0';
	strcat(file, "_ascii.pgm");

	fp2=fopen(file, "w");

	fscanf(fp1, "%s", mag_no);
	if(strcmp(mag_no, "P5")!=0)
	{
		printf("\nIMAGE FORMAT NOT SUPPORTED!");
		getch();
		exit(0);
	}
	while(width<0)
	{
		fgets(line, 300, fp1);
		sscanf(line, "%d%d%d", &width, &height, &maxval);
	}
	
	while(height<0)
	{
		fgets(line, 300, fp1);
		sscanf(line, "%d%d", &height, &maxval);
	}
	while(maxval<0)
	{
		fgets(line, 300, fp1);
		sscanf(line, "%d", &maxval);
	}
	fprintf(fp2, "P2\n%d %d\n%d\n", width, height, maxval);
	for(i=0; i<width*height; i++)
	{
		fgets(ch, 2, fp1);
		if(ch=="\n")
		{
			fgets(ch,2,fp1);
		}
		if(ctr==10)
		{
			fprintf(fp2,"\n");
			ctr=0;
		}
		ctr++;
		if((int)ch == 10 || (int)ch == 32)
		{
			fputs(ch, fp2);
		}
		else
		{
			if((int)ch[0]<0)
			{
				fprintf(fp2, "%d\t", (int)ch[0]+maxval+1);
			}
			else
			{
				fprintf(fp2, "%d\t", (int)ch[0]);
			}
		}
	}
	fclose(fp1);
	fclose(fp2);
}
