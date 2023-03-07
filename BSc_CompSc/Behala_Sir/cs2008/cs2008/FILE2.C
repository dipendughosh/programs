#include<stdio.h>
#include<conio.h>
#include<string.h>
void main(int argc,char *argv[])
{
 FILE *fp;
 char ch,ttl[200];
 int cho,i=0,sen,word,flag=0;
 if(argc!=3)
  {
   printf("\nParameter missing...");
   exit();
  }
 fp=fopen(argv[1],"r+");
 if(fp==NULL)
  {
   printf("\nFile not found...");
   exit();
  }
 while(1)
  {
   ch=getc(fp);
   if(ch==EOF)
     break;
   ttl[i]=ch;
   i++;
  }
 ttl[i]='\0';
 fclose(fp);
 //switch(argv[2])
  //{
   if(!strcmp(argv[2],"-l"))
    {
     flag=1;
     sen=0;
     for(i=0;i<strlen(ttl);i++)
       if(ttl[i]=='.')
	 sen++;
     printf("\n\nTotal no. of line: %d",sen);
     printf("\n\nJOB DONE SUCCESSFULLY...\n\n");
    }
   //if(argv[2]=='-c')
   if(!strcmp(argv[2],"-c"))
    {
     printf("\n\nTotal no. of charector: %d",strlen(ttl));
     printf("\n\nJOB DONE SUCCESSFULLY...\n\n");
     flag=1;
    }
   //if(argv[2]=='-w')
   if(!strcmp(argv[2],"-w"))
    {
     flag=1;
     word=0;
     for(i=0;i<strlen(ttl);i++)
       if(ttl[i]==' '||ttl[i]=='.')
	  word++;
     printf("\n\nTotal no. of words: %d",word);
     printf("\n\nJOB DONE SUCCESSFULLY...\n\n");
    }
   if(!flag)
     printf("\n\nInvalid parameter passing...\n\n");
}


