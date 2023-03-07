#include<stdio.h>

int main()
{
  FILE *fin,*fout,*fout2;
  char ch;
  int thres=0;
  int r,g,b;
  int i=0,j=0;
  int c;
  int avg;
  
  fin = fopen("image.jpg","r");
  if(fin == NULL)
  {
    printf("Cannot open source file:::::Exiting.............");
  }
  
  fout = fopen("imageTemp.txt","w");
  if(fout == NULL)
  {
    printf("Cannot open destination file:::::Exiting.............");
  }
  
  fout2 = fopen("imageTemp1.jpg","w");
  if(fout == NULL)
  {
    printf("Cannot open destination file:::::Exiting.............");
  }
  
  //Finding the threshold value and also recreating the image
  do
  {
    //For red
    fscanf(fin,"%c",&ch);
    r = ((int)ch);
    thres = thres + r;
    fprintf(fout,"%d\n",r);
    
    //For green
    fscanf(fin,"%c",&ch);
    g = ((int)ch);
    thres = thres + g;
    fprintf(fout,"%d\n",g);
    
    //For blue
    fscanf(fin,"%c",&ch);
    b = ((int)ch);
    thres = thres + b;
    fprintf(fout,"%d\n",b);
    
    //ReCreating the image
    ch = (char)r;
    fprintf(fout2,"%c",ch);
    ch = (char)g;
    fprintf(fout2,"%c",ch);
    ch = (char)b;
    fprintf(fout2,"%c",ch);
    
    
    
    /*fscanf(fin,"%c",&ch);
    c = ((int)ch);
    r = (int)(c >> 16) & 0xFF;
    g = (int)(c >> 8) & 0xFF;
    b = (int)(c >> 0) & 0xFF;
    
    thres = thres + r + g + b;
    
    ch = (char)c;
    fprintf(fout2,"%c",ch);
    */
    i++;
  }while(!feof(fin));
  
  printf("\nThreshold value : = %d\n",thres,i);
  thres = thres/i;
  printf("\nThreshold value : = %d\n",thres);
  //thres = 5;
  
  fclose(fin);
  fclose(fout);
  fclose(fout2);
  
  fin = fopen("image.jpg","r");
  if(fin == NULL)
  {
    printf("Cannot open source file:::::Exiting.............");
  }
  
  fout2 = fopen("imageTemp2.jpg","w");
  if(fout == NULL)
  {
    printf("Cannot open destination file:::::Exiting.............");
  }
  
  //Converting to greyscale
  do
  {
    avg = 0;
    //For red
    fscanf(fin,"%c",&ch);
    r = ((int)ch);
       
    //For green
    fscanf(fin,"%c",&ch);
    g = ((int)ch);
        
    //For blue
    fscanf(fin,"%c",&ch);
    b = ((int)ch);
        
    avg = (r + g + b)/3;
    
    if(avg < thres)
      avg = 0;
    else
      avg = 1;
    ch = (char)avg;
    fprintf(fout2,"%c",ch);
	fprintf(fout2,"%c",ch);
	fprintf(fout2,"%c",ch);
	
	/*    
    fscanf(fin,"%c",&ch);
    c = ((int)ch);
    r = (int)(c >> 16) & 0xFF;
    g = (int)(c >> 8) & 0xFF;
    b = (int)(c >> 0) & 0xFF;
    
    avg = r + g + b;
    avg = avg / 3;
    
    if(avg < thres)
      avg = 128;
    else
      avg = 255;
    
    
    c = (avg<<16)|(avg<<8)|(avg);
    ch = (char)c;
    fprintf(fout2,"%c",ch);*/
  }while(!feof(fin));
  
  fclose(fin);
  fclose(fout2);
  
  return 0;
}